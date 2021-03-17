#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "Yes" << endl
#define cn cout << "No" << endl
#define ld long double
#define mod 1000000009

void _run()
{    
    int n,k;
    cin >> n >> k;
    string a,b;
    cin >> a >> b;
    int fa[26];
    int fb[26];
    memset(fa,0,sizeof(fa));
    memset(fb,0,sizeof(fb));

    if(k == 1)
    {
        sort(a.begin() , a.end());
        sort(b.begin(),b.end());
        for(int i = 0 ; i < n ; i++)
        {
            if(a[i] > b[i])
            {
                cn;
                return;
            }
        }
        cy;
        return;
    }

    for(int i = 0 ; i < n ; i++)
    {
        fa[a[i] - 'a']++;
        fb[b[i] - 'a']++;
    }
    if(fa[25] > fb[25])
    {
        cn;
        return;
    }
    int left = 0;
    for(int i = 0 ; i < 26 ; i++)
    {
        if(abs(fa[i] - fb[i]) % k != 0)
        {
            cn;
            return;
        }
    }
    cy;
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
