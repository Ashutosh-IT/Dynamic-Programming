/*

Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.


Input: N = 4
arr = {1, 5, 11, 5}
Output: YES
Explanation: 
The two parts are {1, 5, 5} and {11}.

*/

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0; i<N; i++)
        sum += arr[i];
        
        if(sum&1) return 0;
        sum /= 2;
        
        int dp[N+1][sum+1];
        
        for(int i=0; i<=N; i++){
            dp[i][0] = 1;
        }
        
        for(int i=1; i<=sum; i++){
            dp[0][i] = 0;
        }
        
        for(int i=1; i<=N; i++){
            for(int j=1; j<=sum; j++){
                if(j-arr[i-1] >= 0)
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][sum];
    }
};
