/*

Given an array of n positive integers. 
Find the sum of the maximum sum subsequence of the given array such that the integers in the subsequence are sorted in strictly increasing order i.e. a strictly increasing subsequence.

Input: 
N = 5, arr[] = {1, 101, 2, 3, 100} 
Output: 
106
Explanation:
The maximum sum of a increasing sequence is obtained from {1, 2, 3, 100},

*/

class Solution{
		
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int ans = arr[0];
	    
	    int dp[n];
	    dp[0] = arr[0];
	    
	    for(int i=1; i<n; i++){
	        dp[i] = arr[i];
	        for(int j=0; j<i; j++){
	            if(arr[i] > arr[j])
	            dp[i] = max(dp[i], dp[j] + arr[i]);
	        }
	        ans = max(ans,dp[i]);
	    }
	    
	    return ans;
	}  
};
