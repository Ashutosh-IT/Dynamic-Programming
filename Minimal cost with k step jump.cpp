/*


There are n stones and an array of heights and Geek is standing at stone 1 and can jump to one of the following: 
Stone i+1, i+2, ... i+k stone and cost will be [hi-hj] is incurred, where j is the stone to land on. 
Find the minimum possible total cost incurred before the Geek reaches Stone N.


*/


class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        
        int dp[n];
        
        dp[0] = 0;
        dp[1] = abs(height[0]-height[1]);
        
        for(int i=2; i<n; i++){
            dp[i] = INT_MAX;
            for(int j=1; j<=k; j++){
                if(i-j<0) break;
                dp[i] = min(abs(height[i]-height[i-j])+dp[i-j],dp[i]);
            }
        }
        
        return dp[n-1];
    }
};
