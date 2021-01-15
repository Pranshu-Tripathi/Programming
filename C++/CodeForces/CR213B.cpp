#include<bits/stdc++.h>
using namespace std;
#define ll long long

void _run()
{
    int n;
    cin >> n;
    bool che[n] = {false};
    che[0] = che[1] = true;
    ll seq[n];
    for(int i = 0 ; i < n ; i++)
        cin >> seq[i];
    
    if(n == 1)
    {
        cout << 1 << endl;
        return;
    }
    for(int l = 2 ; l < n ; l++)
    {
        if(seq[l] == (seq[l-1] + seq[l-2]))
            che[l] = true;
    }
    int cnt = 2;
    int mxcnt =2;

    // for(int c : che)
    // {
    //     cout << c << " ";
    // }
    // cout << endl;

    for(int i = 2 ; i < n ; i++)
    {
        if(!che[i])
        {
            mxcnt = max(mxcnt,cnt);
            cnt = 2;
        }
        else
        {
            cnt++;
        }
    }
    mxcnt = max(cnt,mxcnt);
    cout << mxcnt << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;
    while(test--)
        _run();
    return 0;
}