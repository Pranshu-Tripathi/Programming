#include<bits/stdc++.h>
using namespace std;

bool vis[101][100001];
static long long  dp[101][100001];


long long Dp(int N, int W, int w[],long long v[] ){
    if(N == 0 || W <= 0){
        return 0;
    }if(vis[N][W]){
        
        return dp[N][W];
    }else{
        long long x = Dp(N-1,W,w,v);
        if(w[N] > W){
            vis[N][W] = true;
            dp[N][W] = x;
            return dp[N][W];
        }else{
            long long y = Dp(N-1,W-w[N],w,v);
            vis[N][W] = true;
            dp[N][W] = max(x,y+v[N]);
            return dp[N][W];
        }
    }

}

void init(){
    for(int i = 0 ; i <= 100 ; i++){
        for(int j = 0 ; j <= 100001 ; j++){
            if(i != 0){
                vis[i][j] = false;
            }else{
                vis[i][j] = true;
            }
        }
    }
}

int main(){
    int N,W;
    cin >> N >> W;
    init();

    

    int w[N+1];
    long long  v[N+1];

    for(int i = 1; i  <= N ;i ++){
        cin >> w[i] >> v[i];
    }

    for(int i = 0 ; i <= N; i++){
        dp[0][i] = 0;
    }

    long long ans = Dp(N,W,w,v);

    for(int i = 0 ; i <= N ; i++){
        for(int j = 0 ; j <=N ; j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    
    cout  << ans ;
}