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

#define mod 1000000007


static int dp[1001][100001];
bool vis[1001][100001];


void init(int n, int x)
{
    int i,j;
    FOR(i,0,n)
    {
        FOR(j,0,x)
        {
            if(i != 0){
                vis[i][j] = false;
            }else{
                vis[i][j] = true;
            }
        }
    }
}

ll DP(int n, int x, int price[] , int pages[])
{
    if(n == 0 || x <= 0)    return 0;
    if(vis[n][x])   return dp[n][x];
    else
    {
        int y = DP(n-1,x,price,pages);
        vis[n][x] = true;
        if(x - price[n] < 0)
        {
            dp[n][x] = y;
            return dp[n][x];
        }
        else
        {
            int z = DP(n-1,x-price[n],price,pages);
            dp[n][x] = max(y,z+pages[n]);
            return dp[n][x]; 
        }
    }
}

int main()
{
    int n,x,i,j;
    cin >> n >> x;
    init(n,x);

    int price[n+1];
    int pages[n+1];

    FORE(i,1,n)
    {
        cin >> price[i];
    }

    FORE(i,1,n)
    {
        cin >> pages[i];
    }

    for(int i = 0 ; i <= n; i++){
        dp[0][i] = 0;
    }

    ll ans = DP(n,x,price,pages);
    cout << ans << endl;

}