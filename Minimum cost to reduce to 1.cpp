/*


Given an integer “N” ; find the minimum cost to reduce it to 1
The operations you can do are as follows.->

i) Reduce the number by 1 in “y” dollars; 

ii) Reduce the number by /7 in “x” dollars.(if number is divisible by 7)

iii) Reduce the number by /3 in “z” dollars;(if number is divisible by 3)

iv) Reduce the number by /5 in “b” dollars;(if number is divisible by 5) 

(1<=n<=100000)


Understanding :->

N = 15 

Y = 100 
X = 1 
Z = 500 
B = 10000000



*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int x,y,z,b;
    cin>>x>>y>>z>>b;
    
    int dp[n+1];
    dp[1] = 0;
    
    for(int i=2; i<=n; i++){
        int opt1 = y + dp[i-1];
        int opt2 = i%7 == 0 ? x + dp[i/7] : 1e9;
        int opt3 = i%3 == 0 ? z + dp[i/3] : 1e9;
        int opt4 = i%5 == 0 ? b + dp[i/5] : 1e9;
        
        dp[i] = min(min(opt1,opt2),min(opt3,opt4));
    }
    
    cout<<dp[n];
}
