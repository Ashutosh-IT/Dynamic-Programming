class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size()==1) return nums[0];

        // last element not considered
        int n=nums.size()-1;
        int dp[n];

        if(n>0) dp[0] = nums[0];
        if(n>1) dp[1] = max(nums[0],nums[1]);
        if(n>2) dp[2] = max(nums[2]+dp[0],dp[1]);

        for(int i=3; i<n; i++){
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }

        // first element not considered
        int dp2[n+1];
        if(n+1>1) dp2[1] = nums[1];
        if(n+1>2) dp2[2] = max(nums[1],nums[2]);

        for(int i=3; i<=n; i++){
            dp2[i] = max(nums[i]+dp2[i-2],dp2[i-1]);
        }

        return max(dp[n-1],dp2[n]);
    }
};
