class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int dp[n][4];

        dp[0][0] = INT_MAX;
        dp[0][1] = costs[0];
        dp[0][2] = costs[1];
        dp[0][3] = costs[2];

        for(int i=1; i<n; i++){
            // agar us din koi ticket nhi kharida
            dp[i][0] = INT_MAX;
            int k=i-1;
            while(k>=0 && days[i] - days[k] < 30){
                if(days[i] - days[k] < 7)
                dp[i][0] = min(dp[i][0],dp[k][2]);
                dp[i][0] = min(dp[i][0],dp[k][3]);
                k--;
            }

            // agar ticket kharida
            for(int j=1; j<4; j++){
                int x = min(dp[i-1][0],min(dp[i-1][1],min(dp[i-1][2],dp[i-1][3])));
                dp[i][j] = x + costs[j-1];
            }
        }

        int ans = min(dp[n-1][0],min(dp[n-1][1],min(dp[n-1][2],dp[n-1][3])));
        return ans;
    }
};
