int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[n+1][W+1];
       
       for(int i=0; i<=W; i++){
           dp[0][i] = 0;
       }
       
       for(int i=1; i<=n; i++){
           dp[i][0] = 0;
       }
       
       for(int i=1; i<=n; i++){
           for(int j=1; j<=W; j++){
               int opt1 = dp[i-1][j];
               int opt2 = 0;
               
               if(j-wt[i-1]>=0) 
               opt2 = val[i-1] + dp[i-1][j-wt[i-1]];
               
               dp[i][j] = max(opt1,opt2);
           }
       }
       
       return dp[n][W];
    }
