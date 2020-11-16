#include<bits/stdc++.h>
using namespace std;
#define N 100001

vector <int> ways(N,0);
vector <bool> vis(N,false);  

int minWays(int n);
void solve();

int main(){
    int test;
    cin >> test;
    while(test--){
        vis[0] = vis[1] =  vis[2] =  vis[3] = true;
        ways[0] = ways[1] = ways[2] = ways[3] = 1;
        solve();
    }
}

void solve(){
    int n;
    cin >> n;
    cout << minWays(n) << endl;
}

int minWays(int n){
    if(vis[n]){
        return ways[n];
    }
    else{
        vis[n] = true;
        ways[n] = min(min(minWays(n-1),minWays(n-2)),minWays(n-3)) + 1;
        return ways[n];
    }
}