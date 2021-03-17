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

void _query(string& s)
{
    string z = "%";
    z += s;
    int l,r;
    cin >> l >> r;
    char firstCharacter = z[l];
    char lastCharacter = z[r];
    int x,y;
    for(int i = 1 ; i < z.length() ; i++)
    {
        if(firstCharacter == z[i])
        {
            x = i;
            break;
        }
    }
    for(int i = z.length()-1 ; i >= 0 ; i--)
    {
        if(lastCharacter == z[i])
        {
            y = i;
            break;
        }
    }
    
    if(x < l || y > r)
        cy;
    else
        cn;
    return;
}

void _run()
{    
    int n,q;
    cin >> n >> q;
    string inp;
    cin >> inp;
    while(q--)
        _query(inp);
    return;
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
