/*

Find the number of journeys where you start from index 1 and end at index ‘n’ and the sum of every journey should be odd..

-> Similarly find for even. 

Allowed to make jumps of size 1 or 2 


*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0; i<n; i++)
    cin>>arr[i];
    
    int dp[n][2];
    // dp[i][0] = even
    // dp[i][1] = odd
    
   
    if(arr[0]&1){
        dp[0][0] = 0;
        dp[0][1] = 1;
    }
    else{
        dp[0][0] = 1;
        dp[0][1] = 0;
    }
    
    if(arr[1]&1){
        dp[1][0] = dp[0][1];
        dp[1][1] = dp[0][0];
    }
    else{
        dp[1][0] = dp[0][0];
        dp[1][1] = dp[0][1];
    }
    
    for(int i=2; i<n; i++){
        if(arr[i]&1){
            dp[i][0] = dp[i-1][1] + dp[i-2][1];
            dp[i][1] = dp[i-1][0] + dp[i-2][0];
        }
        else{
            dp[i][0] = dp[i-1][0] + dp[i-2][0];
            dp[i][1] = dp[i-1][1] + dp[i-2][1];
        }
    }
    
    cout<<"Even Journey "<<dp[n-1][0]<<endl;
    cout<<"Odd Journey "<<dp[n-1][1]<<endl;
}
