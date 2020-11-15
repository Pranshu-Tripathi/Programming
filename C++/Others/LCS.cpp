#include <bits/stdc++.h>
using namespace std;


// bool vis[3001][3001];
int dp[3001][3001];

void init(){
    for(int i = 0 ;  i<=3000 ; i++){
        for(int j = 0 ; j <= 3000 ; j++){
            // vis[i][j] = false;
            if(i== 0 || j ==  0){
                //vis[i][j] = true;
                dp[i][j] = 0;
            }
        }
    }
}

int  LCS(int m,int n,string s,string t){
    if(n <= 0 || m <= 0){
        return 0;
    }
    // if(vis[m][n]){
    //     return dp[m][n];
    // }
    else{
        if(s[m-1] == t[n-1]){
            dp[m][n] = LCS(m-1,n-1,s,t) + 1;
            //vis[m][n] = true;
            return dp[m][n];
        }else{
            dp[m][n] = max(LCS(m-1,n,s,t),LCS(m,n-1,s,t));
            //vis[m][n] = true;
            return  dp[m][n];
        }
    }
}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    string t;
    cin >> s >> t;

    int m = s.length();
    int n = t.length();

    init();

    int ans = LCS(m,n,s,t);


    vector <char> strg;

    int row = m;
    int col = n ;

    while(row > 0 && col > 0){
        if(dp[row][col] != dp[row-1][col] && dp[row][col] != dp[row][col-1]){
            strg.push_back(s[row-1]);
            row--;
            col--;
        }
        else if(dp[row][col] == dp[row-1][col]){
            row--;
        }
        else if(dp[row][col] == dp[row][col-1]){
            col--;
        }
    }
    for(int i = strg.size()-1;i >=0 ; i--){
        cout << strg[i];
    }
    
}