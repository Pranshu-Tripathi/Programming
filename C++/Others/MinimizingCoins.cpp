/*
We have to use minimum number of coins to get a target x value.
*/

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

int main()
{
    int j,i,n,x;
    cin >> n >> x;
    int arr[n];
    FOR(i,0,n)
    {
        cin >> arr[i];
    }

    ll dp[x+1];
    memset(dp,1e9+7,sizeof(dp));

    dp[0] = 0;
    
    FORE(i,1,x)
    {
        FOR(j,0,n)
        {
            if(i-arr[j] >= 0)
            {
                dp[i] = min(dp[i],dp[i-arr[j]] + 1);
            }
        }
    }

   

    if(dp[x] == 506381209866536711)    cout << -1;
    else cout << dp[x];
}