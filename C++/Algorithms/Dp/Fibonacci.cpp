/*
Finding Fibonacci Numbers using DP.
Top to down approach .
*/

#include<bits/stdc++.h>
using namespace std;
#define N 100001
vector <int> vis(N,false);
vector <long long> dp(N,0);

long long fib(int n){
    if(n < 2){
        return n;
    }
    else if(vis[n]){
        return dp[n];
    }
    else{
        dp[n] = fib(n-1)+fib(n-2);
        vis[n] = true;
        return dp[n];
    }
}

void solve(){
    int n;
    cin >> n;
    cout << fib(n) <<endl;
}


int main(){
    int test;
    cin >> test;

    while(test--){
        solve();
    }
}