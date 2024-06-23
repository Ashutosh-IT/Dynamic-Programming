/*

You are given an integer array nums with length n.

The cost of a 
subarray
 nums[l..r], where 0 <= l <= r < n, is defined as:

cost(l, r) = nums[l] - nums[l + 1] + ... + nums[r] * (−1)r − l

Your task is to split nums into subarrays such that the total cost of the subarrays is maximized, ensuring each element belongs to exactly one subarray.

Formally, if nums is split into k subarrays, where k > 1, at indices i1, i2, ..., ik − 1, where 0 <= i1 < i2 < ... < ik - 1 < n - 1, then the total cost will be:

cost(0, i1) + cost(i1 + 1, i2) + ... + cost(ik − 1 + 1, n − 1)

Return an integer denoting the maximum total cost of the subarrays after splitting the array optimally.

Note: If nums is not split into subarrays, i.e. k = 1, the total cost is simply cost(0, n - 1).

*/

class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        int n = nums.size();

        long long dp[n][2];

        dp[0][0] = nums[0];
        dp[0][1] = INT_MIN;

        for(int i=1; i<n; i++){
            dp[i][0] = nums[i] + max(dp[i-1][0],dp[i-1][1]);
            dp[i][1] = -nums[i] + dp[i-1][0];
        }

        return max(dp[n-1][0],dp[n-1][1]);
    }
};

