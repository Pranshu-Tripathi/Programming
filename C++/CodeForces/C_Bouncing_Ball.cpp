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
    int n,p,k;
    cin >> n >> p >> k;
    string s;
    cin >> s;
    int x,y;
    cin >> x >> y;
    int dp[n];
    int q = p - 1;
    memset(dp,0,sizeof(dp));
    for(int i = n - 1 ; i >= 0 ; i--)
    {
        int t = 0;
        int c_i_k = i + k;
        if(i+k < n)
            t = dp[i+k];
        dp[i] = t + ('1' - s[i]);
    }

    ll bst = 1000000000;

    for(int i = q ; i < n ; i++)
    {
        ll val = (i - q)*y + dp[i]*x;
        bst = min(bst,val);
    }

    cout << bst << endl;
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
