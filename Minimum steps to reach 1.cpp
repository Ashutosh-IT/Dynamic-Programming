/*

Given a number N, the task is to count minimum steps to minimize it to 1 according to the following criteria:

If N is divisible by 2 then you may reduce N to N/2.
If N is divisible by 3 then you may reduce N to N/3.
Otherwise, Decrement N by 1.


*/

class Solution{

	public:
	int minSteps(int N) 
	{ 
	    // create dp array
	    int dp[N+1] = {0};
	   
	    //base cases
	    dp[1] = 0;
	    dp[2] = 1;
	    dp[3] = 1;
	    dp[4] = min(1+dp[3],1+dp[2]);
	    
	   // fill dp array
	   for(int i=5; i<=N; i++){
	       if(i%3 == 0){
	           dp[i] = min(1+dp[i-1],1+dp[i/3]);
	       }
	       else if(i%2 == 0){
	           dp[i] = min(1+dp[i-1],1+dp[i/2]);
	       }
	       else{
	           dp[i] = 1+dp[i-1];
	       }
	   }
	   return dp[N];
	} 
};
