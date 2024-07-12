/*

Given an array a[ ] of n integers, find the Length of the Longest Strictly Increasing Subsequence.

A sequence of numbers is called "strictly increasing" when each term in the sequence is smaller than the term that comes after it.

Expected Time Complexity : O( n*log(n) )
Expected Auxiliary Space: O(n)

*/

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       vector<int> ans;
       ans.push_back(a[0]);
       
       for(int i=1; i<n; i++){
           if(a[i] > ans.back())
           ans.push_back(a[i]);
           int index = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
           ans[index] = a[i];
       }
       
       return ans.size();
    }
};
