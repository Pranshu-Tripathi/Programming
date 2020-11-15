#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,K;
    cin >> N >> K;
    int arr[N];
    for(int i = 0; i < N ; i++){
        cin >> arr[i];
    }

    bool dp[K+1];

    memset(dp,false,sizeof(dp));

    for(int i =1; i <= K ; i++){
        for(auto a : arr){
            if(i >= a){
                if(!dp[i-a]){
                    dp[i] = true;
                }
            }else{
                continue;
            }
        }
    }

    cout << (dp[K]?"First":"Second");

}