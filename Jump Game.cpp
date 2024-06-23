/*

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.


*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        bool dp[n];

        dp[0] = true;
        if(n>1) dp[1] = nums[0] == 0 ? false : true;

        for(int i=2; i<n; i++){
            dp[i] = false;
            for(int j=i-1; j>=0; j--){
                int dist = i-j;
                if(nums[j] >= dist && dp[j] == true){
                    dp[i] = true;
                    break;
                }
            }
        }  
        return dp[n-1];
    }
};
