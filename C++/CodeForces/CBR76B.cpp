#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

void _run()
{
    int m;
    cin>>m;
    int acq[6]={0};
    for(int i=0;i<m;i++){
        int a, b;
        cin>>a>>b;
        acq[a]++,acq[b]++;
    }
    bool flag = true;
    for(int i=1;i<=5;i++){
        if(acq[i]>=3||acq[i]<=1) flag = false;
    }
    if(!flag) cout<<"WIN\n";
    else cout<<"FAIL\n";
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
