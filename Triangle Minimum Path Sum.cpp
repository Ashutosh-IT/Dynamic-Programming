/*


Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. 
More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).


*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();

        int dp[n][n];

        dp[0][0] = triangle[0][0];
        if(n>1) dp[1][0] = dp[0][0] + triangle[1][0];
        if(n>1) dp[1][1] = dp[0][0] + triangle[1][1];

        for(int i=2; i<n; i++){
            for(int j=0; j<=i; j++){
                int opt1 = i!=j ? dp[i-1][j] + triangle[i][j] : INT_MAX;
                int opt2 = j-1 >= 0 ? dp[i-1][j-1] + triangle[i][j] : INT_MAX;
                dp[i][j] = min(opt1,opt2);
            }
        }

        int ans = INT_MAX;
        for(int i=0; i<n; i++)
        ans = min(ans,dp[n-1][i]);

        for(int i=0; i<n; i++){
            for(int j=0; j<=i; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }

        return ans;
    }
};
