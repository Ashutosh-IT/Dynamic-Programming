/*

Given a string str of length N, you have to find number of palindromic subsequence (need not necessarily be distinct) present in the string str.
Note: You have to return the answer module 109+7;
 


*/

class Solution{
    public:
    
    int mod = 1e9+7;
    
    /*You are required to complete below method */
    long long int  countPS(string str)
    {
       int n = str.size();
       
       long long dp[n][n];
       // dp[i][j] -- number of palindromic subsequences in range (i--j)
       
       for(int i=0; i<n; i++)
       dp[i][i] = 1;
       
       for(int i=0; i<n-1; i++){
           if(str[i] == str[i+1]){
               dp[i][i+1] = 3;
           }
           else dp[i][i+1] = 2;
       }
       
       int length = 3;
       
       while(length <= n){
           for(int i=0; i<=n-length; i++){
               int j=i+length-1;
               
               if(str[i] != str[j]){
                   dp[i][j] = (dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] + mod) % mod;
               }
               else{
                   dp[i][j] = (dp[i+1][j]%mod + dp[i][j-1]%mod + 1)%mod;
               }
           }
           length++;
       }
       
       return (dp[0][n-1])%mod;
    }
     
};
