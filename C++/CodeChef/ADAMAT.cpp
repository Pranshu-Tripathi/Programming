#include <bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin >> n;
    vector<vector<int>> arr(n,vector<int>(n));
    vector<bool> issue(n);



    for(int i = 0 ; i < n ; i ++){
        for(int j = 0 ;  j < n ; j++){
            cin >> arr[i][j];
        }
    }

    bool state = false;

    int ans = 0;

    int start,end;

    for(int i = 0 ; i < n ; i++){
        if(arr[0][i] != i+1){
            start = i;
            break;
        }
    }
    bool check = false;
    for(int i = n-1 ; i >= 0 ; i--){
        if(arr[0][i] != i+1){
            end = i;
            check = true;
            break;
        }
    }

    if(!check){
        cout << 0 <<endl;
        return;
    }

    for(int i = 0 ; i<n ; i++){
        if(arr[0][i] != i+1){
            issue[i] = false;
        }
        else{
            issue[i] = true;
        }
    }
    
    for(int i = start+1;i <= end ; i++){
        if(issue[i] != issue[i-1]){
            if(!issue[i]){
                ans++;
            }
        }
    }

    ans++;

    if(start != 1){
        ans = 2*ans;
    }else{
        ans = 2*ans-1;
    }

    cout << ans << endl;

}


int main(){
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    
}