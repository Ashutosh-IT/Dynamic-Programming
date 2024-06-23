/*


You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int dp[n];

        dp[0] = 0;
        if(n>1) dp[1] = nums[0] == 0 ? 0 : 1;

        for(int i=2; i<n; i++){
            dp[i] = 1e9;
            for(int j=i-1; j>=0; j--){
                int dist = i-j;
                if(nums[j] >= dist){
                    dp[i] = min(dp[i],1+dp[j]);
                }
            }
            if(dp[i] == 1e9) dp[i] = 0;
        }

        for(int i=0; i<n; i++) cout<<dp[i]<<" ";
        return dp[n-1];
    }
};
