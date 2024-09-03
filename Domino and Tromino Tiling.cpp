/*

https://leetcode.com/problems/domino-and-tromino-tiling/


You have two types of tiles: a 2 x 1 domino shape and a tromino shape. You may rotate these shapes.
Given an integer n, return the number of ways to tile an 2 x n board. Since the answer may be very large, return it modulo 10^9 + 7.

In a tiling, every square must be covered by a tile. 
Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.

*/

class Solution {
public:
    int numTilings(int n) {

        int mod = 1e9+7;

        long long dp[n+1];
        long long dp_up[n+1];
        long long dp_down[n+1];

        dp[0] = 1;
        dp_down[0] = dp_up[0] = 0;

        dp[1] = 1;
        dp_down[1] = dp_up[1] = 0;

        if(n>1){
            dp[2] = 2;
            dp_up[2] = dp_down[2] = 1; 
        }

        for(int i=3; i<=n; i++){
            long long opt1 = dp[i-1];
            long long opt2 = dp[i-2];
            long long opt3 = dp_down[i-1];
            long long opt4 = dp_up[i-1];

            dp[i] = (opt1 + opt2 + opt3 + opt4)%mod;

            dp_down[i] = (dp_up[i-1] + dp[i-2])%mod;
            dp_up[i] = (dp_down[i-1] + dp[i-2])%mod; 
        }

        return dp[n];
    }
};
