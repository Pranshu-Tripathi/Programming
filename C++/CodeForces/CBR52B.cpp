#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    int seq[n+1];
    for(int i = 1 ; i <= n ; i++)
    {
        seq[i] = i;
    }
    int sta = -1,en = -1;

    for(int i = 1;  i<= n ; i++)
    {
        if(a[i] != seq[i])
        {
            sta = i;
            break;
        }
    }

    for(int i = n ; i >= 1 ; i--)
    {
         if(a[i] != seq[i])
        {
            en = i;
            break;
        }
    }
    if(sta != -1 && en != -1)
        reverse(a.begin() + sta  , a.begin() + en + 1);
    for(int i = 1 ; i <= n ; i++)
    {
        if(a[i] != seq[i])
        {
            cout << 0 << ' ' << 0 << endl;
            return;
        }
    }
    if(sta != -1 && en != -1)
        cout << sta << ' ' << en << endl;
    else
        cout << 0 << ' ' << 0 << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
