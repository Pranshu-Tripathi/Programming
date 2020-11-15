#include <bits/stdc++.h>

using namespace std;


long long Dp(int n , int k,int h[] , bool vis[] , long long dp[]){
    if(vis[n]){
        return dp[n];
    }else{
        vector <int> back;
        for(int step = 1 ; step <= k ; step++){
            if(n - step >= 0){
                int x = Dp(n-step,k,h,vis,dp) + abs(h[n] - h[n-step]);
                back.push_back(x);
            }
        }
        sort(back.begin(),back.end());
        vis[n] = true;
        dp[n] = back[0];
        return dp[n];
    }
}



void init(int n , bool vis[]){
    vis[0] = true;
    for(int i = 1; i < n ; i++){
        vis[i] = false;
    }
}

int main(){

    int n,k;
    cin >> n >> k;
    int h[n];
    bool vis[n];
    long long dp[n];
    dp[0] = 0;
    init(n,vis);
    for(int i = 0 ; i < n ; i++){
        cin >> h[i];
    }
    long long ans = Dp(n-1,k,h,vis,dp);
    cout << ans;
    return 0;
}