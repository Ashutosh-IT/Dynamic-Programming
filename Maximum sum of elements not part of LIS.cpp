/*

Given an array Arr[], the task is to find the maximum sum of all the elements which are not a part of the longest increasing subsequence.

n = 6
Arr = {4, 6, 1, 2, 4, 6}
Output: 10
Explaination: Elements are 4 and 6.

*/

class Solution {
  public:
    int maxSumLis(int a[], int n) {
        // code here
        
       vector<int> ans;
       vector<int> insertIndex(n);
       ans.push_back(a[0]);
       insertIndex[0] = 1;
       
       for(int i=1; i<n; i++){
           if(a[i] > ans.back()){
               ans.push_back(a[i]);
               insertIndex[i] = ans.size();
           }
           else{
               int index = lower_bound(ans.begin(),ans.end(),a[i]) - ans.begin();
               insertIndex[i] = index+1;
               ans[index] = a[i];
           }
       }
       
       
       vector<int> LIS;
       int curr = ans.size();
       
       for(int i=n-1; i>=0; i--){
           if(insertIndex[i] == curr){
               LIS.push_back(a[i]);
               curr--;
           }
       }
       
       
       reverse(LIS.begin(),LIS.end());
       
       int sum = 0;
       int j=0;
       
       for(int i=0; i<n; i++){
           if(j<LIS.size() && a[i] == LIS[j]){
               j++;
           }
           else{
               sum += a[i];
           }
       }
        
       return sum;
    }
};
