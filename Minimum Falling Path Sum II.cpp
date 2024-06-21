/*

Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.

A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.

*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int dp[n][n];

        for(int i=0; i<n; i++)
        dp[0][i] = matrix[0][i];

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j] = INT_MAX;
                for(int k=0; k<n; k++){
                    if(k!=j)
                    dp[i][j] = min(dp[i][j],dp[i-1][k]+matrix[i][j]);
                }
            }
        }


        int ans = INT_MAX;

        for(int i=0; i<n; i++)
        ans = min(ans,dp[n-1][i]);


        return ans;
    }
};

