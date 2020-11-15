/*
Number of Ways to Reach A number n using a dice.
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

#define m 1000000007

ll dp[1000001] = {0};
int vis[1000001] = {0};

ll com(int n)
{
    if(n < 0)
    {
        return 0;
    }
    else if(vis[n] == 1)
    {
        return dp[n];
    }
    else
    {
        dp[n] = (com(n-1)%m + com(n-2)%m + com(n-3)%m + com(n-4)%m + com(n-5)%m + com(n-6)%m)%m;
        vis[n] = 1;
        return dp[n];
    }
    
}

int main()
{
    int n;
    cin >> n;
    dp[1] = vis[1] = vis[0] = dp[0] = 1;
    cout << com(n) << endl;
    
}