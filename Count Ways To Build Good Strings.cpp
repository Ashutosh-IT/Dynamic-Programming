class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high,0);
        int MOD = 1e9+7;

        dp[zero-1] += 1;
        dp[one-1] += 1;
        
        for(int i=0; i<high; i++){
            int opt1 = i-zero >= 0 ? dp[i-zero] : 0;
            int opt2 = i-one >= 0 ? dp[i-one] : 0;
            dp[i] += (opt1%MOD + opt2%MOD) % MOD;
        }

        int ans = 0;
        for(int i=low-1; i<high; i++) ans = (ans%MOD + dp[i]%MOD) % MOD;

        return ans;
    }
};
