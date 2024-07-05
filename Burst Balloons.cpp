/*

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];

        vector<int> arr(n+2,1);
        for(int i=0; i<n; i++) arr[i+1] = nums[i];

        vector<vector<int>> dp(n+5,vector<int>(n+5,0));

        for(int i=1; i<=n; i++)
        dp[i][i] = arr[i-1]*arr[i]*arr[i+1];

        int length = 2;
        while(length <= n){
            for(int i=1; i<=n-length+1; i++){
                int j=i+length-1;
                dp[i][j] = 0;
                for(int k=i; k<=j; k++){
                    dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + arr[k]*arr[i-1]*arr[j+1]);
                }
            }
            length++;
        }

        return dp[1][n];
    }
};
