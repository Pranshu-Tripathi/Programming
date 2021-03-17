#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double

void _run()
{
    ll n;
    cin >> n;
    ll a = 3,b,c,ans = 0;

    while(true)
    {
        
        b = (a * a - 1)/2;
        c = b + 1;
        if(c > n)
            break;
        a+= 2;
        ans++;
    }
    
    cout << ans << endl;

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
