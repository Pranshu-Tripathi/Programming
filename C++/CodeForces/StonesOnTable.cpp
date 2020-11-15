#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    string st;
    cin >> st;

    for(int i = 1 ; i  < n ; i ++){
        if(st[i] == st[i-1]){
            ans++;
        }
    }

    cout << ans;
}