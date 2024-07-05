/*

Given an integer array A of size N. You have to merge all the elements of the array into one with the minimum possible cost.

The rule for merging is as follows:

Choose any two adjacent elements of the array with values say X and Y and merge them into a single element with value (X + Y) paying a total cost of (X + Y).
Return the minimum possible cost of merging all elements.

*/

int Solution::solve(vector<int> &A) {
    
    int n = A.size();
    if(n == 1) return 0;
    if(n == 2) return A[0] + A[1];
    
    int sum[n];
    sum[0] = A[0];
    for(int i=1; i<n; i++)
    sum[i] = sum[i-1] + A[i];
    
    int dp[n][n];
    for(int i=0; i<n; i++)
    dp[i][i] = 0;
    
    for(int i=0; i<n-1; i++)
    dp[i][i+1] = A[i] + A[i+1];
    
    int length = 3;
    while(length <= n){
        for(int i=0; i<=n-length; i++){
            int j = i+length-1;
            dp[i][j] = 1e9;
            for(int k=i; k<=j-1; k++)
            dp[i][j] = min(dp[i][j],(i==0 ? sum[j] : sum[j] - sum[i-1]) + dp[i][k] + dp[k+1][j]);
        }
        length++;
    }
    return dp[0][n-1];
    
}
