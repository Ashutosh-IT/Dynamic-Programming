#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int arr[n+1];
    for(int i=1; i<=n; i++)
    cin>>arr[i];
    
    
    // find greatest element on left
    stack<int> st;
    vector<int> leftMax(n+1,0);
    for(int i=n; i>=1; i--){
        if(st.empty()){
            st.push(i);
        }
        if(arr[st.top()] >= arr[i]){
            st.push(i);
        }
        else{
            leftMax[st.top()] = i;
            st.pop();
            i++;
        }
    }
    
    // solve dp problem
    int dp[n+1]={0};
    dp[1] = 0;
    
    vector<int> prefixMax(n+1,0);
    
    for(int i=2; i<=n; i++){
        int u=leftMax[i];
        if(leftMax[i]==0){
          dp[i] = 0;
        }
        else{
            dp[i] = prefixMax[u-1] + 1;
        }
        prefixMax[i] = max(prefixMax[i-1],dp[i]);
    }
    
    cout<<dp[n];
}
