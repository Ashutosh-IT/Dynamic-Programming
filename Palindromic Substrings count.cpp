/*

Given a string s, count all palindromic sub-strings present in the string. The length of the palindromic sub-string must be greater than or equal to 2. 

Note:  The string contains only lowercase english characters.


*/

class Solution {
  public:
    int CountPS(char s[], int n) {
        // code here
        
        int dp[n][n];
        // dp[i][j] -> index (i -- j) is palindromic substring or not
        
        for(int i=0; i<n; i++)
        dp[i][i] = 1;
        
        int count = 0;
        
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                count++;
            }
            else dp[i][i+1] = 0;
        }
        
        int length = 3;
        
        while(length <= n){
            for(int i=0; i<=n-length; i++){
                int j = i+length-1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                    count++;
                }
                else dp[i][j] = 0;
            }
            length++;
        }
        
        return count;
    }
};
