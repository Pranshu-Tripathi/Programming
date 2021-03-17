#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000009

void _run()
{    
    int n;
    cin >> n;
    int a[n+1];
    int f[n+1];
    int idx = -1;
    memset(f,0,sizeof(f));
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i],f[a[i]]++;
    
    for(int i = 1 ; i <= n ; i++)
    {
        if(f[i] == 1)
        {
            idx = i;
            break;
        }
    }
    for(int i = 1 ; i <= n ; i++)
    {
        if(a[i] == idx)
        {
            idx = i;
            break;
        }
    }

    cout << idx << endl;
}

int main()
{
    fast;
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
