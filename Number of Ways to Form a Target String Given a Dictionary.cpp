class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int m = words[0].size();
        int MOD = 1e9+7;


        // making it long long to handle overflow integer
        vector<vector<long long>> freq(26,vector<long long>(m,0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int ch = words[i][j]-'a';
                freq[ch][j]++;
            }
        }

        int sz = target.size();
        vector<vector<int>> dp(m,vector<int>(sz,0));

        //base cases
        dp[0][0] = freq[target[0]-'a'][0];

        for(int i=1; i<m; i++)
        dp[i][0] = dp[i-1][0] + freq[target[0]-'a'][i]; 
        
        for(int i=0; i<m; i++){
            for(int j=1; j<sz; j++){
                if(i<j) dp[i][j] = 0;
                else{
                    long long opt1 = dp[i-1][j];
                    long long opt2 = ((dp[i-1][j-1]%MOD) * (freq[target[j]-'a'][i]%MOD)) % MOD;
                    dp[i][j] = (opt1%MOD + opt2%MOD) % MOD;
                }
            }
        }

        return dp[m-1][sz-1];
    }
};
