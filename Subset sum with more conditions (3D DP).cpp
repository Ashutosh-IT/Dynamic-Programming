// Find the total number of ways to make number "N" using the numbers {1,2,4,6}
// condition : 4 and 6 can be used at max 2 times


#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    // 1,2,4,6
    
    vector<vector<vector<int>>> dp(n+1,vector<vector<int> >(3, vector<int>(3,0)));
    
    dp[0][0][0] = 1;
    
    dp[1][0][0] = 1;
    
    for(int i=2; i<=n; i++){
        dp[i][0][0] = dp[i-1][0][0] + dp[i-2][0][0];
        dp[i][0][1] = dp[i-1][0][1] + dp[i-2][0][1];
        dp[i][0][2] = dp[i-1][0][2] + dp[i-2][0][2];
        
        dp[i][1][0] = dp[i-1][1][0] + dp[i-2][1][0];
        dp[i][1][1] = dp[i-1][1][1] + dp[i-2][0][1];
        dp[i][1][2] = dp[i-1][1][2] + dp[i-2][1][2];
        
        dp[i][2][0] = dp[i-1][2][0] + dp[i-2][2][0];
        dp[i][2][1] = dp[i-1][2][1] + dp[i-2][2][1];
        dp[i][2][2] = dp[i-1][2][2] + dp[i-2][2][2];
        
        if(i>=6){
            dp[i][0][1] += dp[i-6][0][0];
            dp[i][0][2] += dp[i-6][0][1];
            dp[i][1][1] += dp[i-6][1][0];
            dp[i][1][2] += dp[i-6][1][1];
            dp[i][2][1] += dp[i-6][2][0];
            dp[i][2][2] += dp[i-6][2][1];
        }
        if(i>=4){
            dp[i][1][0] += dp[i-4][0][0];
            dp[i][1][1] += dp[i-4][0][1];
            dp[i][1][2] += dp[i-4][1][2];
            dp[i][2][0] += dp[i-4][1][0];
            dp[i][2][1] += dp[i-4][1][1];
            dp[i][2][2] += dp[i-4][1][2];
        }
    }
    
    int ans = dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][1][2] + dp[n][2][0] + dp[n][2][1] + dp[n][2][2];
    cout<<ans;
}
