/*

Given a floor of dimensions 2 x n and tiles of dimensions 2 x 1, the task is to find the number of ways the floor can be tiled. 
A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile. return the answer with modulo 109+7.

n = 3
Output: 3
Explanation:
We need 3 tiles to tile the boardof size  2 x 3. 
We can tile in following ways:
1) Place all 3 tiles vertically. 
2) Place first tile verticallyand remaining 2 tiles horizontally.
3) Place first 2 tiles horizontally and remaining tiles vertically.

*/

class Solution {
  public:
    int numberOfWays(int n) {
        
        int dp[n];
        dp[0] = 1;
        dp[1] = 2;
        dp[2] = 3;
        
        int mod = 1e9+7;
        
        for(int i=3; i<n; i++){
            dp[i] = ((dp[i-1]%mod) + (dp[i-2]%mod))%mod;
        }
        
        return dp[n-1];
    }
};
