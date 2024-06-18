/*


Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps.
A height[N] array is also given. Whenever the geek jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]),
where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.


*/


class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int dp[n];
        dp[0] = 0;
        if(n>1)
        dp[1] = abs(height[1]-height[0]);
        if(n>2)
        dp[2] = min(abs(height[2]-height[0]),abs(height[2]-height[1])+dp[1]);
        
        for(int i=3; i<n; i++){
            dp[i] = min(abs(height[i]-height[i-2])+dp[i-2],abs(height[i]-height[i-1])+dp[i-1]);
        }
        
        return dp[n-1];
    }
};
