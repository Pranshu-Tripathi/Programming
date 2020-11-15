#include<bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector <double> prob(N);

    for(int i = 0; i < N ; i++){
        cin >> prob[i];
    }

    vector<vector<double>>dp(N+1,vector<double>(N+1));

    dp[0][0] = 1.0;

    for(int i = 1; i <= N ; i++){
        for(int j = 0 ; j<=N ; j++){
            if(j ==0){
                dp[i][j] = (1.0-prob[i-1])*dp[i-1][j];
            }else{
                dp[i][j] = prob[i-1]*dp[i-1][j-1] + (1.0-prob[i-1])*dp[i-1][j];
            }
        }
    }

    float sum = 0.0;
    for(int i = N/2+1 ; i  <= N ; i++){
        sum+=dp[N][i];
    }

    printf("%.10lf",sum);

}