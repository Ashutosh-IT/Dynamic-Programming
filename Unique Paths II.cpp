/*

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). 
The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.


*/


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m =  obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1){
            return 0;
        }

        int dp[n][m];

        dp[0][0] = 1;
        for(int i=1; i<n; i++){
            if(obstacleGrid[i][0]==1){
                dp[i][0] = 0;
            }
            else{
                dp[i][0] = dp[i-1][0];
            }
        }
        
        for(int i=1; i<m; i++){
            if(obstacleGrid[0][i]==1){
                dp[0][i] = 0;
            }
            else{
                dp[0][i] = dp[0][i-1];
            }
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = dp[i-1][j]+dp[i][j-1];
                }
            }
        }

        return dp[n-1][m-1];
    }
};
