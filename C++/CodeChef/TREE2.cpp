#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin >> n;

    vector<long long> a(n);

    for(int i = 0; i < n ; i ++ ){
        cin >> a[i];
    } 
    int operation = 1;
    sort(a.begin(),a.end(),greater<long long>());

    if(a[0] != 0){
        for(int i = 1 ;i < n ; i++){
            if(a[i] != 0){
                if(a[i] != a[i-1]){
                    operation++;
                }
            }else{
                break;
            }
        }
    }else{
        operation = 0;
    }

    cout << operation << endl;
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}