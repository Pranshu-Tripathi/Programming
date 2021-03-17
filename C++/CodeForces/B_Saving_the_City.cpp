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

void _run()
{    
    int a,b;
    cin >> a >> b;
    string s;
    cin >> s;
    int fone = s.length();
    for(int i = 0 ; i < s.length() ; i++)
        if(s[i] == '1')
        {
            fone = i;
            break;
        }
    
    int dp[s.length()+5];
    int cnts[s.length()+5];
    memset(dp,0,sizeof(dp));
    memset(cnts,-1,sizeof(cnts));

    for(int i = 0 ; i < s.length() ; i++)
        if(s[i]== '1')
            cnts[i] = 0;
    
    int sum = 0;
    for(int i = fone+1 ; i < s.length() ; i++)
    {
        if(s[i] == '1')
            cnts[i] = abs(sum),sum = 0;
        else
            sum += cnts[i];
    }
    dp[fone] = a;
    for(int i = fone+1 ; i < s.length() ; i++)
    {
        if(cnts[i] > 0)
            dp[i] = min(dp[i-1]+a,dp[i-1]+ cnts[i]*b);
        else
            dp[i] = dp[i-1];
    }
    cout << dp[s.length() -1] << endl;
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
