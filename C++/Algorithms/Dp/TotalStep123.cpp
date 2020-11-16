/* Find Total Number of ways of reaching nth stair using 1,2,3 steps */

#include<bits/stdc++.h>
using namespace std;
#define N  1000001
vector <long long> ways(N,0);
vector <bool> vis(N,false);


int totalWays(int n){
    if(vis[n]){
        return ways[n];
    }
    else{
        vis[n] = true;
        ways[n] = totalWays(n-1)+totalWays(n-2)+totalWays(n-3);
        return ways[n];
    }
}


void solve(){
    int n;
    cin >> n;
    cout << totalWays(n) << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        ways[0] = 1; vis[0] = true;
        ways[1] = 1; vis[1] = true;
        ways[2] = 2; vis[2] = true;
        solve();
    }
}