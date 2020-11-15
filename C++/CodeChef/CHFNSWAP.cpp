#include <bits/stdc++.h>
using namespace std;

long long Combination(long long int c){
    return (c*(c-1))/2;
}


long long findDiv(long long n,long long x){
    long double delta = 1+8*(x);
    long double rootFunc = ((long double)-1+sqrt(delta))/2;

    if(rootFunc - (long long) rootFunc == 0){
        return n-(long long) rootFunc + Combination((long long )rootFunc) + Combination( n-(long long) rootFunc) ;
    }else{
        return n-(long long)rootFunc;
    }
}


void solve(){
    long long n;
    cin >> n;

    long long ans = 0;

    if(n%4 == 1 || n%4 == 2){
        cout << ans << endl;
        return;
    }
    long long x = n*(n+1)/4;

    ans = findDiv(n,x);
    cout << ans << endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}