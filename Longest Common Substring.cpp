/*

You are given two strings str1 and str2. Your task is to find the length of the longest common substring among the given strings.

Input: str1 = "ABCDGH", str2 = "ACDGHR"
Output: 4
Explanation: The longest common substring is "CDGH" which has length 4.

*/

class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        
        int n = str1.size();
        int m = str2.size();
        
        int dp[n][m];
        int ans = 0;
        
        
        // dp[i][j] = best answer when str1 is of length i && str2 is of length j && str1[i] and str2[j] character is included in the answer
        
        for(int i=0; i<n; i++){
            dp[i][0] = str1[i] == str2[0];
            ans = max(ans,dp[i][0]);
        }
        
        
        for(int j=0; j<m; j++){
            dp[0][j] = str1[0] == str2[j];
            ans = max(ans,dp[0][j]);
        }
        
        
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                
                // case1 : character match
                if(str1[i] == str2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
                
                // case2 : not match
                else dp[i][j] = 0;
                
                ans = max(ans,dp[i][j]);
                
            }
        }
        
        
        return ans;
        
    }
};
