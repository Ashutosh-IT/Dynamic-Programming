/*

Taro's summer vacation starts tomorrow, and he has decided to make plans for it now.

The vacation consists of N days. For each i (1 ≤ i ≤ N), Taro will choose one of the following activities and do it on the i-th day:

A: Swim in the sea. Gain a[i] points of happiness.
B: Catch bugs in the mountains. Gain b[i] points of happiness.
C: Do homework at home. Gain c[i] points of happiness.
As Taro gets bored easily, he cannot do the same activities for two or more consecutive days.

Find the maximum possible total points of happiness that Taro gains.


  */



#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  
  int a[n], b[n], c[n];
  for(int i=0; i<n; i++)
  cin>>a[i]>>b[i]>>c[i];
  
  int dp[n][3];
  // dp[i][0] => activity A
  // dp[i][1] => activity B
  // dp[i][2] => activity C
  
  dp[0][0] = a[0], dp[0][1] = b[0], dp[0][2] = c[0];
  
  for(int i=1; i<n; i++){
    dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + a[i]; 
    dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + b[i];
    dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + c[i];
  }
  
  cout << max(dp[n-1][0], max(dp[n-1][1],dp[n-1][2]));
}
