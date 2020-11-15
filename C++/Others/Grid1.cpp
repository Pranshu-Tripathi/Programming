#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007

int main(){
    int Height,Width;
    cin >> Height >> Width;

    vector <string> s(Height);

    vector<vector<int>> dp(Height,vector<int>(Width));
    dp[0][0] = 1;

    for(int i = 0 ; i < Height ; i++){
        cin >> s[i];
    }

    for(int i = 0 ; i < Height; i ++){
        for(int j = 0 ; j < Width ; j++){
            if(s[i][j] == '#'){
                dp[i][j] = 0;
                continue;
            }
            else if(i==0 && j ==0){
                continue;
            }
            else if(i == 0){
                dp[i][j] = dp[i][j-1];
            }else if(j == 0){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = (dp[i-1][j] % mod + dp[i][j-1] % mod)%mod; 
            }
        }
    }
    cout << dp[Height-1][Width-1];
}