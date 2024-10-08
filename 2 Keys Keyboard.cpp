/*

There is only one character 'A' on the screen of a notepad. You can perform one of two operations on this notepad for each step:

Copy All: You can copy all the characters present on the screen (a partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given an integer n, return the minimum number of operations to get the character 'A' exactly n times on the screen.

*/

class Solution {
public:
    int minSteps(int n) {
        
        int dp[n+1];
        dp[1] = 0;
        if(n>1) dp[2] = 2;
        if(n>2) dp[3] = 3;

        for(int i=4; i<=n; i++){
            dp[i] = i;
            for(int j=2; j<=i/2; j++){
                if(i%j == 0)
                dp[i] = min(dp[i],dp[j]+i/j);
            }
        }

        return dp[n];
    }
};
