#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

int ans;

bool isvalid(ll num)
{
    unordered_set<int> digs;
    while(num)
    {
        digs.insert(num%10);
        num/=10;
    }

    return digs.size() <= 2;
}

void dfs(ll num, ll limit)
{
    if(num > 0 && num <= limit)
        ans++;
    else
        return;
    for(int i = 0 ; i <= 9 ; i++)
    {
        if(isvalid(num*10+i))
            dfs(num*10+i,limit);
    }
    return;
}

void _run()
{
    ll n;
    cin >> n;
    for(int i = 1 ; i <= 9 ; i ++)
        dfs(i,n);
    cout << ans << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
