/*

Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

NOTE: We can start from any column in zeroth row and can end at any column in (N-1)th row.

*/


class Solution{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        // code here
        int dp[n][n];

        for(int i=0; i<n; i++)
        dp[0][i] = matrix[0][i];

        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int opt1 = dp[i-1][j] + matrix[i][j];
                int opt2 = j-1>=0 ? dp[i-1][j-1] + matrix[i][j] : INT_MIN;
                int opt3 = j+1<n ? dp[i-1][j+1] + matrix[i][j] : INT_MIN;
                dp[i][j] = max(opt1,max(opt2,opt3));
            }
        }

        int ans = INT_MIN;

        for(int i=0; i<n; i++)
        ans = max(ans,dp[n-1][i]);

        return ans;
        
    }
};
