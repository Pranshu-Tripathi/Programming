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

void _validate(vector<vector<ll>>& a , int i , int j)
{
    int k = i + j;
    if(k%2 == 0)
    {
        if(a[i][j] % 2 != 0)
            a[i][j]++;
    }
    else
    {
        if(a[i][j] % 2 == 0)
            a[i][j]++;
    }
}


void _run()
{    
    int n,m;
    cin >> n >> m;
    vector<vector<ll>> a(n+1,vector<ll>(m+1));

    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            cin >> a[i][j];
    
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
            _validate(a,i,j);
    
    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= m ; j ++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
            
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
