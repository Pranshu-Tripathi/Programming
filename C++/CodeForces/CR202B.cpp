#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false); \
                        cin.tie(NULL)
#define ll long long

void _run()
{
    int n;
    cin >> n;
    int a[10];
    for(int i = 1 ; i <= 9 ; i++)
        cin >> a[i];
    int len[10];
    int idx = -1,Ml  = 0;
    for(int i = 9 ; i >= 1 ; i--)
    {
        len[i] = n/a[i];
        if(Ml<len[i])
        {
            Ml = len[i];
            idx = i;
        }
    }
    if(idx == -1)
    {
        cout << -1 << endl;
        return ;
    }

    for(int i = 1 ; i <= 9 ; i++)
        cout << len[i] << ' ';
    cout << endl;

    vector<int> ans(Ml);
    for(int i = 0 ; i < Ml;i++)
        ans[i] = idx;
    
    int leftover = n - Ml*a[idx];

    if(leftover == 0)
    {
        for(int k : ans)
            cout << k;
        return ;
    }

    for(int i = 9 ; i >= idx ; i--)
    {
        if(leftover + a[idx] >= a[i])
        {
            cout << i;
            break;
        }
    }
    for(int i = 1;i < Ml ; i++)
        cout << ans[i];
}

int main()
{
    fast;
    int test = 1;
    while(test--)
        _run();
    return 0;
}