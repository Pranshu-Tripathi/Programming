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

void _run()
{    
    int n;
    cin >> n;
    if(n <= 30)
        cn;
    else
    {
        cy;
        if(n - 30 == 6)
        {
            cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << n - 31 << endl;
        }
        else if(n-30 == 10)
        {
            cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << n - 31 << endl;
        }
        else if(n-30 == 14)
        {
            cout << 6 << ' ' << 10 << ' ' << 15 << ' ' << n - 31 << endl;
        }
        else
        {
            cout << 6 << ' ' << 10 << ' ' << 14 << ' ' << n - 30 << endl;
        }
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
