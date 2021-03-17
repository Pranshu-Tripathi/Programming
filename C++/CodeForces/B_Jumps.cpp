/*
PR7
*/
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
#define debug(a...) cout<<#a<<": ";for(auto it:a)cout<<it<<" ";cout<<endl;

ll a[1000001];

void  _precom()
{
    a[0] = 0;
    for(int i = 1 ; i <= 1000000 ; i++)
        a[i] = a[i-1]+i;
}

void _run()
{    
    int n;
    cin >> n;
    int pos = 0;
    for(; pos <= n ; pos++)
        if(a[pos] >= n)
            break;
    int dif = a[pos] - n;
    if(dif == 0)
        cout << pos << endl;
    else if(dif - 1 != 0 && dif - 1 < pos)
        cout << pos << endl;
    else
    {
        cout << a[pos] - n + pos << endl;
    }
}

int main()
{
    fast;
    int test;
    cin >> test;
    _precom();
    while(test--)
        _run();
    return 0;
}
