#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl


void _run()
{
    string s;
    cin>>s;
    vector<int> ans(s.size());
    int for_r=0,for_l=s.size()-1;
    for(int i=0;i<s.size();i++){
        if(s[i]=='l')ans[for_l]=i+1,for_l--;
        if(s[i]=='r') ans[for_r]=i+1,for_r++;
    }
    for(int x:ans)printf("%d\n",x);
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
