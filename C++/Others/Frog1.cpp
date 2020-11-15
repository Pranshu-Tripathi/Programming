#include <bits/stdc++.h>
using namespace std;

long long Dp(int n,int h[] , bool vis[] , long long dp[]){
    if(vis[n]){
        return dp[n];
    }else{
        int x,y;
        x = y = __INT_MAX__;
        if(n - 1 >=0){
            x = Dp(n-1,h,vis,dp) + abs(h[n] - h[n-1]);
        }if(n-2 >= 0){
            y = Dp(n-2,h,vis,dp) + abs(h[n] - h[n-2]);
        }

        vis[n] = true;
        dp[n] = min(x,y);

        cout << endl;
        return dp[n];
    }
}

void init(int n,bool vis[]){
    for(int i = 0 ; i < n ; i++){
        if(i == 0){
            vis[i] = true;
        }else{
            vis[i] = false;
        }
    }
}

int main(){

    int n;
    cin >> n;
    int h[n];
    bool vis[n];
    long long dp[n];
    dp[0] = 0;
    init(n,vis);
    for(int i = 0 ; i < n ; i++){
        cin >> h[i];
    }

    long long ans = Dp(n-1,h,vis,dp);
    // for(int i = 0 ; i < n ; i++){
    //     cout << dp[i] << " ";
    // }
    cout << ans;
    return 0;
}