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
    ll a[n],b[n];
    for(int i = 0  ; i < n ; i++)
        cin >> a[i];
    for(int i = 0 ; i < n ; i++)
        cin >> b[i];
    ll moves = 0;
    ll fa = *min_element(a,a+n);
    ll fb = *min_element(b,b+n);

    for(int i = 0 ;  i < n ; i++)
    {
        ll am = a[i] - fa;
        ll mb = b[i] - fb;
        moves += min(am,mb);
        moves += max(am,mb) - min(am,mb);
    }
    cout << moves << endl;

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
