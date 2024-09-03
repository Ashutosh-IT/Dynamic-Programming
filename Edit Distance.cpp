/*

Given two strings str1 and str2. Return the minimum number of operations required to convert str1 to str2.
The possible operations are permitted:

Insert a character at any position of the string.
Remove any character from the string.
Replace any character from the string with any other character.

Input: str1 = "geek", srt2 = "gesek"
Output: 1
Explanation: One operation is required, inserting 's' between two 'e'.

*/

class Solution {
  public:
    int editDistance(string str1, string str2) {
        
        int n = str1.size(), m = str2.size();
        
        int dp[n+1][m+1];
        
        // dp[i][j] = minimum operations to convert str1 i length equal to str2 j length 
        
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                
                if(i==0 || j==0)
                dp[i][j] = i+j;
                
                else if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            
                else{
                    int opt1 = 1+dp[i][j-1];
                    int opt2 = 1+dp[i-1][j];
                    int opt3 = 1+dp[i-1][j-1];
                    
                    dp[i][j] = min(opt1,min(opt2,opt3));
                }
            }
        }
        
        
        return dp[n][m];
    }
};
