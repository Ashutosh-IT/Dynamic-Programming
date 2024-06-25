/*


You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        int dp[n+1][amount+1];

        for(int i=0; i<=n; i++)
        dp[i][0] = 1;

        for(int i=1; i<=amount; i++)
        dp[0][i] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=amount; j++){
                int opt1 = dp[i-1][j];
                int opt2 = 0;
                if(j-coins[i-1] >= 0)
                opt2 = dp[i][j-coins[i-1]];

                dp[i][j] = opt1 + opt2;
            }
        }

        return dp[n][amount];
    }
};
