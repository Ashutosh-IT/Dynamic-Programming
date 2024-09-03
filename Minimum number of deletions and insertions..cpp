/*

Given two strings str1 and str2. The task is to remove or insert the minimum number of characters from/in str1 so as to transform it into str2. 
It could be possible that the same character needs to be removed/deleted from one point of str1 and inserted to some another point.

Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion.
p and h deleted from heap. Then, p is inserted at the beginning.
One thing to note, though p was required yet it was removed/deleted first from its position and then it is inserted to some other position. 
Thus, p contributes one to the deletion_count and one to the insertion_count.

*/

class Solution{
		
	public:
	int minOperations(string str1, string str2) 
	{ 
	    int n = str1.size();
	    int m = str2.size();
	    
	    int dp[n+1][m+1];
	    
	   // base cases
	   dp[0][0] = 0;
	   
	   for(int i=1; i<=n; i++)
	   dp[i][0] = i;
	   
	   for(int j=1; j<=m; j++)
	   dp[0][j] = j;
	   
	   for(int i=1; i<=n; i++){
	       for(int j=1; j<=m; j++){
	           dp[i][j] = INT_MAX;
	           
	           // character matches
	           if(str1[i-1] == str2[j-1])
	           dp[i][j] = dp[i-1][j-1];
	           
	           // character not matches
	           else{
	               int opt1 = 1 + dp[i-1][j];
	               int opt2 = 1 + dp[i][j-1];
	               dp[i][j] = min(opt1,opt2);
	           }
	       }
	   }
	   
	   return dp[n][m];
	    
	} 
};
