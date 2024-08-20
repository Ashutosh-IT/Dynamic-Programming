/*

Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. 
This continues until there are no more piles left, at which point the person with the most stones wins.

Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.


*/


class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        int dp[n][n];

        for(int i=0; i<n; i++)
        dp[i][i] = piles[i];

        for(int i=0; i<n-1; i++)
        dp[i][i+1] = max(piles[i],piles[i+1]);

        int length = 3;
        while(length <= n){
            for(int i=0; i<=n-length; i++){
                int j=i+length-1;
                dp[i][j] = 0;

                // opt1 : first pile
                int opt1 = piles[i] + max(dp[i+1][j-1],dp[i+2][j]);

                // opt2 : last pile
                int opt2 = piles[j] + max(dp[i][j-2],dp[i+1][j-1]);

                dp[i][j] = max(opt1,opt2);
            }
            length++;
        }

        int count = dp[0][n-1];
        int sum = 0;
        for(int i=0; i<n; i++) sum += piles[i];
        return sum-count < count;

    }

    
};
