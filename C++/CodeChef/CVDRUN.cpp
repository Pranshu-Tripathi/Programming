#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0) , cin.tie(0),cout.tie(0);
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

const string r = "YES";
const string n_r = "NO";

void solve()
{
    int n,k,x,y;
    cin >> n >> k >> x >> y;
    int vis[n] = {0};
    if(k == 1 || x == y)
    {
        cout << r << endl;
        return;
    }

    int sta = (x+k)%n;

    while(sta != x)
    {   
        vis[sta] = 1;
        sta = (sta+k)%n;
    }

    if(vis[y] == 0)
    {
        cout << n_r << endl;
    }
    else
    {
        cout << r << endl;
    }
    
}


int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        solve();
    }
}