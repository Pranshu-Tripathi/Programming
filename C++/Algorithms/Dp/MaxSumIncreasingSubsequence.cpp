/*
Find the maximum sum of among all the increasing subsequences
*/

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int arr[n];
    int mi[n];
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
        mi[i] = arr[i];
    }
    int maximum_sum = mi[0];
    for(int i = 1 ; i < n ; i++){
        for(int j = 0 ; j < i ; j++){
            if(arr[i] > arr[j] && arr[i] + mi[j] > mi[i]){
                mi[i] = arr[i] + mi[j];
            }
        }
        maximum_sum = max(maximum_sum,mi[i]);
    }
    for(int i = 0 ; i< n ;i++){
        cout << mi[i] << " ";
    }
    cout <<endl<< maximum_sum << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}