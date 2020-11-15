#include <bits/stdc++.h>
using namespace std;

#define ll long long 

void solve()
{
    string s;
    int x;
    cin>>s;
    cin>>x;
    string ans(s.size(),'0');
    // cout<<ans<<endl;
    for(int i=0;i<s.size();i++){
        if(i-x>=0&&s[i]=='0'){
            if(ans[i-x]!='0'){
                cout<<"-1\n";
                return;
            }
        }
        if(s[i]=='1'){
            if(i-x>=0){
                ans[i-x]='1';
            }
            if(i+x<s.size()){
                ans[i+x]='1';
            }
        }

    }
    cout<<ans<<endl;


}

int main(){
    ll t;
    cin>>t;
    while(t--)
        solve();
}