int FindMaxSum(int arr[], int n)
    {
        // its a DP problem similar to maximum subset sum with no two adjacent 
      
        // steps :
        
        // 1. create dp array
        int dp[n]={0};
        
        // 2. fill the some base cases in dp array
        dp[0] = arr[0];
        dp[1] = max(dp[0],arr[1]);
        dp[2] = max(dp[0]+arr[2],dp[1]);
        
        // 3. fill the whole dp array using loop and formula
        for(int i=3; i<n; i++){
            
            // 4. find the general formula
            // dp[4] = max(dp[2]+arr[4],dp[3]) -- include 4th element or not
            
            dp[i] = max(dp[i-2]+arr[i],dp[i-1]);
        }
        
        // return the last element of dp array
        return dp[n-1];
        
    }
