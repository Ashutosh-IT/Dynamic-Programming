int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        int mod = 1e9+7;
        
        if(grid[0][0]==0) return 0; 
        
        // create dp array
        int dp[n][m];
        
        // base cases
        dp[0][0] = 1;
        for(int i=1; i<n; i++){
            if(grid[i][0]==0) dp[i][0] = 0;
            else dp[i][0] = dp[i-1][0];
        }
        
        for(int j=1; j<m; j++){
            if(grid[0][j]==0) dp[0][j] = 0;
            else dp[0][j] = dp[0][j-1];
        }
        
        
        // fill the dp array
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                if(grid[i][j]==0) dp[i][j] = 0;
                else dp[i][j] = (dp[i-1][j]%mod + dp[i][j-1]%mod)%mod;
            }
        }
        
        
        // return the dp[n-1][n-1];
        return dp[n-1][m-1];
        
    }
