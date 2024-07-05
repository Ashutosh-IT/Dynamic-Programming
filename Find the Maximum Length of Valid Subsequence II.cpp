/*

You are given an integer array nums and a positive integer k.
A subsequence sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % k == (sub[1] + sub[2]) % k == ... == (sub[x - 2] + sub[x - 1]) % k.
Return the length of the longest valid subsequence of nums.


Constraints:

2 <= nums.length <= 10^3
1 <= nums[i] <= 10^7
1 <= k <= 10^3

*/

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        
        int ans = 0;
        int n = nums.size();

        int dp[n][k];
        for(int i=0; i<n; i++){
            for(int j=0; j<k; j++)
            dp[i][j] = 1;
        }

        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                int mod = (nums[i] + nums[j]) % k;
                dp[i][mod] = max(dp[i][mod],1 + dp[j][mod]);
                ans = max(ans,dp[i][mod]);
            }
        }

        return ans;

    }
};
