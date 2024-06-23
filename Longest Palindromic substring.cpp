/*

Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). 
Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. 
Incase of conflict, return the substring which occurs first ( with the least starting index ).

*/

class Solution{   
public:
    string longestPalindrome(string s){
        
        int n = s.size();
        
        int dp[n][n];
        // dp[i][j] -> index (i -- j) is palindromic substring or not
        
        for(int i=0; i<n; i++)
        dp[i][i] = 1;
        
        int maxLength = 1;
        int start=0, end=0;
        
        for(int i=0; i<n-1; i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                if(maxLength < 2){
                    maxLength = 2;
                    start = i;
                    end = i+1;
                }
            }
            else dp[i][i+1] = 0;
        }
        
        int length = 3;
        
        while(length <= n){
            for(int i=0; i<=n-length; i++){
                int j = i+length-1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j] = 1;
                    if(maxLength < j-i+1){
                        maxLength = j-i+1;
                        start = i;
                        end = j;
                    }
                }
                else dp[i][j] = 0;
            }
            length++;
        }
        
        string ans = "";
        for(int i=start; i<=end; i++)
        ans.push_back(s[i]);
        
        return ans;
    }
};
