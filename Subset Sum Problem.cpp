/*

Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.



*/

class Solution{   
public:
    bool isSubsetSum(vector<int>wt, int sum){
        // code here 
        
        int n = wt.size();
        
        bool dp[n+1][sum+1];
        
        for(int i=0; i<=n; i++) dp[i][0] = true;
        for(int j=1; j<=sum; j++) dp[0][j] = false;
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                
                bool opt1 = dp[i-1][j];
                
                bool opt2 = false;
                if(j-wt[i-1] >= 0)
                opt2 = dp[i-1][j-wt[i-1]];
                
                dp[i][j] = opt1 | opt2;
            }
        }
        return dp[n][sum];
    }
};
