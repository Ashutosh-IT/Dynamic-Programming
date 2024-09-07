class Solution{
public:
    int matrixMultiplication(int N, int arr[])
    {
        int dp[N][N];
        
        // size 1
        for(int i=0; i<N; i++){
            dp[i][i] = 0;
        }
        
        // size 2
        for(int i=0; i<N-1; i++){
            dp[i][i+1] = 0;
        }
        
        // size 3
        for(int i=0; i<N-2; i++){
            dp[i][i+2] = arr[i]*arr[i+1]*arr[i+2];
        }
        
        
        int length = 4;
        while(length <= N){
            
            for(int i=0; i<=N-length; i++){
                int j = i+length-1;
        
                dp[i][j] = INT_MAX;
                for (int k=i+1; k<j; k++) {
                    int cost = dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j];
                    dp[i][j] = min(dp[i][j],cost);
                }
            }
            
            length++;
        }
        
        return dp[0][N-1];
    }
};
