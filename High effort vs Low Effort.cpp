int maxAmt(int n , int hi[] , int li[])
        {
            //code here. 
            
            // create dp array
            int dp[n][3];
            
            // base cases
            
            // dp[i][0]->low task
            // dp[i][1]->high task
            // dp[i][2]->no task
            
            dp[0][0] = li[0];
            dp[0][1] = hi[0];
            dp[0][2] = 0;
            
            if(n>1){
                dp[1][0] = li[1] + max(dp[0][0], max(dp[0][1],dp[0][2]));
                dp[1][1] = hi[1] + dp[0][2];
                dp[1][2] = max(dp[0][0], max(dp[0][1],dp[0][2]));
            }
            
            // fill the dp array
            for(int i=2; i<n; i++){
                dp[i][0] = li[i] + max(dp[i-1][0], max(dp[i-1][1],dp[i-1][2]));
                dp[i][1] = hi[i] + dp[i-1][2];
                dp[i][2] = max(dp[i-1][0], max(dp[i-1][1],dp[i-1][2]));
            }
            
            
            // return last element of dp
            return max(dp[n-1][0], max(dp[n-1][1],dp[n-1][2]));
        }
