
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

       return LIS;
  }
