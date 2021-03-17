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


bool exists(int x, int n)
{
    return x < n && x >= 0;
}

void _run()
{    
    string s;
    string t="";
    cin >> s;
    int n = s.length();
    int x;
    cin >> x;
    string w = "";
    for(int i = 0 ; i < n ; i++)
        w+= '1',t+= '0';
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == '0')
        {
            if(exists(i-x,n))
                w[i-x] = '0';
            if(exists(i+x,n))
                w[i+x] = '0';
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(exists(i-x,n))
        {
            if(w[i-x] == '1')
                t[i] = '1';
        }
        if(exists(i+x,n))
        {
            if(w[i+x] == '1')
                t[i] = '1';
        }
    }

    if(s == t)
        cout << w << endl;
    else
        cout << -1 << endl;
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
