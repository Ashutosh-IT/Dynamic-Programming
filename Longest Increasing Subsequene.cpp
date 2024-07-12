/*

Given an integer array nums, return the length of the longest strictly increasing 
subsequence


Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

*/

class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();

        int dp[n];
        dp[0] = 1;
       int ans = 1;
       
       for(int i=1; i<n; i++){\
           dp[i] = 1;
           for(int j=0; j<i; j++){
               if(a[j] < a[i]){
                   dp[i] = max(dp[i], dp[j]+1);
               }
           }
           ans = max(ans,dp[i]);
       }
       return ans;
    }
};
