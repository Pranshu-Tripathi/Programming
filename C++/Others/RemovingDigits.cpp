#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0) , cin.tie(0),cout.tie(0);
#define LOG(X)      cout << x << endl;
#define ll long long
#define endl "\n"
#define And &&
#define Or ||
#define FOR(i,a,b)              for(int i = a; i < b; i++)
#define REV(i,a,b)              for(int i = a; i >= b; i--)
#define FORE(i,a,b)             for(int i = a; i <= b; i++)
#define pii                     pair<int,int>
#define pll                     pair< long long int, long long int> 
typedef 						long double ld;
typedef 						unsigned long long ull;
#define F                       first
#define S                       second
#define pb                      push_back

vector<int> digits(int n)
{
    vector <int> D;
    while(n > 0)
    {
        D.push_back(n%10);
        n /= 10;
    }
    reverse(D.begin(),D.end());
    return D;
}

int main()
{
    int j,n,i;
    cin >> n;
    int dp[n+1];
    memset(dp,1000007,sizeof(dp));
    dp[0] = 0;
    FOR(i,1,10) dp[i] = 1;

    FORE(i,10,n)
    {
        vector <int> D = digits(i);
        FOR(j,0,D.size())
        {   
            dp[i] = min(dp[i-D[j]] + 1,dp[i]);
        } 
    }

    cout << dp[n] << endl;

}