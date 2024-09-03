/*

Given two strings pattern and str which may be of different size, You have to return 1 if the wildcard pattern i.e. pattern, matches with str else return 0. All characters of the string str and pattern always belong to the Alphanumeric characters.

The wildcard pattern can include the characters ? and *
‘?’ – matches any single character.
‘*’ – Matches any sequence of characters (including the empty sequence).

Note: The matching should cover the entire str (not partial str).


Input: pattern = "ba*a?", str = "baaabab"
Output: 1
Explanation: replace '*' with "aab" and 
'?' with 'b'.

*/

class Solution {
public:
    int wildCard(string pattern, string str) {
        int n = str.size();
        int m = pattern.size();

        int dp[n][m];
        dp[0][0] = pattern[0] == '*' || pattern[0] == '?' || pattern[0] == str[0];

        // to optimize code to O(nm)
        int one[m];
        memset(one, 0, sizeof(one));
        one[0] = dp[0][0];

        // base cases
        for(int i = 1; i < n; i++) {
            if(pattern[0] == '*') {
                dp[i][0] = 1;
                one[0] = 1;
            } else {
                dp[i][0] = 0;
            }
        }

        bool ch = pattern[0] >= 'a' && pattern[0] <= 'z';
        bool q = pattern[0] == '?';

        for(int j = 1; j < m; j++) {
            // case 1 : *
            if(pattern[j] == '*') {
                dp[0][j] = dp[0][j - 1];
            } 
            // case 2 : ?
            else if(pattern[j] == '?') {
                if(ch || q) {
                    dp[0][j] = 0;
                } else {
                    dp[0][j] = 1;
                    q = true;
                }
            } 
            // case 3 : character
            else {
                if(pattern[j] == str[0]) {
                    if(ch || q) {
                        dp[0][j] = 0;
                    } else {
                        dp[0][j] = 1;
                    }
                } else {
                    dp[0][j] = 0;
                }
            }
            if(dp[0][j]) one[j] = 1;
        }

        // fill dp array
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                // case1 : ?
                if(pattern[j] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } 
                // case2 : *
                else if(pattern[j] == '*') {
                    dp[i][j] = one[j - 1];
                } 
                // case3 : character
                else {
                    if(pattern[j] == str[i]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = 0;
                    }
                }
                if(dp[i][j]) one[j] = 1;
            }
        }

        // return ans
        return dp[n - 1][m - 1];
    }
};
