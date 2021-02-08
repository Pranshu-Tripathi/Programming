#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

void _run()
{
    int n;
    cin >> n;
    ll a[n];
    ll b[n];
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> a[i] ;
        b[i] = a[i];
    }

    sort(b,b+n);
    int count = 0;
    for(int i = 0; i< n ; i++)
    {
        if(a[i] != b[i])
            count++;
    }

    if(count <=2 )
        cy;
    else
        cn;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
