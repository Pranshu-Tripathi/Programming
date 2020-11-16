/* 
Find the length of longest increasing subsequence using dp
This solution is of o(n^2) complexity. A better approach is o(nlogn) saved in a file named LongestIncreasingSubsequenceLengthOPT.cpp
*/

#include <bits/stdc++.h>
using namespace std;

void pranshu(){
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    vector <int> dp(n,1);

    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++ ){
            if(arr[i] > arr[j]){
                if(dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
        }
    }
    sort(dp.begin(),dp.end());
    cout << dp[n-1] << endl;
}

int main(){
    int test;
    test = 1;
    while(test--){
        pranshu();
    }
}