#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define mod 1000000007 

void _run()
{
    int n,m;
    cin >> n >> m;
    vector<string> names(n);
    for(int i = 0 ; i < n ; i ++)
        cin >> names[i];
    ll ans = 1;
    
    for(int i = 0 ; i < m ; i++)
    {
        unordered_set<char> di;
        for(int j = 0 ; j < n ; j++)
        {
            di.insert(names[j][i]);
        }

        int siz = di.size();
        ans  = (ans * siz) % mod;
    }

    cout << ans % mod << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
