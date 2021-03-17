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

int fre[200001];

void _run()
{   
    int n;
    cin >> n;
    int a[n],dp[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i],dp[i] = 0;
    dp[0] = 1;
    for(int i = 1 ; i < n ; i++)
    {
        if(a[i] == a[i-1])
            a[i]++,dp[i] = dp[i-1] + 1;
        else if(a[i] < a[i-1])
            dp[i] = dp[i-1],a[i]++;
        else
            dp[i] = dp[i-1] + 1;
    }
    cout << dp[n-1] << endl;
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
