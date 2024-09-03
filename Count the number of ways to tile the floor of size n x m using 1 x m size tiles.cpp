/*

Given a floor of size n x m and tiles of size 1 x m. The problem is to count the number of ways to tile the given floor using 1 x m tiles. A tile can either be placed horizontally or vertically.
Both n and m are positive integers and 2 < = m.

Input: n = 4, m = 4
Output: 2
Explanation: There is two ways to tile the
given floor.One way is to place 1 x 4 size 
of tile vertically and another one is to 
place them horizontally.


*/

class Solution{
	public:
		int countWays(int n, int m)
	{
	    
	    int dp[n+1];
	    dp[0] = 1;
	    dp[1] = 1;
	    
	    int mod = 1e9+7;
	    
	    for(int i=2; i<=n; i++){
	        int opt1 = dp[i-1];
	        int opt2 = i-m >= 0 ? dp[i-m] : 0;
	        
	        dp[i] = (opt1 + opt2)%mod;
	    }
	    
	    return dp[n];
	}
};
