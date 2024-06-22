/*


Given a set of N items, each with a weight and a value, represented by the array w and val respectively. Also, a knapsack with weight limit W.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.


*/

class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        
        int dp[n+1][w+1];
        
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int i=0; i<=w; i++) dp[0][i] = 0;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=w; j++){
                int opt1 = dp[i-1][j];
                int opt2 = 0;
                
                if(j-wt[i-1]>=0)
                opt2 = val[i-1] + dp[i][j-wt[i-1]];
                dp[i][j] = max(opt1,opt2);
            }
        }
        
        return dp[n][w];
        
    }
};
