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

#define m 1000000007

int main()
{
    int n,x,i,j;
    cin >> n >> x;
    int coins[n];
    FOR(i,0,n)
    {
        cin >> coins[i];
    }

    int dp[x+1] = {0};
    dp[0] = 1;

    FORE(i,1,x)
    {
        FOR(j,0,n)
        {
            if(i - coins[j] < 0)
            {
                continue;
            }
            else
            {
                dp[i] = (dp[i]  +  dp[i - coins[j]])%m;
            }
        }
    }

    cout << dp[x] << endl;
}