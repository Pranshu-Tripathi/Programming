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
    int n,k;
    cin >> n >> k;
    vector<int> a;
    for(int i = k+1 ; i <= n ; i++)
        a.push_back(i);
    bool vis[k+1];
    memset(vis,false,sizeof(vis));
    for(int i = k - 1 ; i >= 1 ; i--)
    {
        if(!vis[i])
        {
            a.push_back(i);
            vis[k-i] = true; 
        }
    }
    cout << a.size() << endl;
    for(int i = 0 ; i < a.size() ; i++)
        cout << a[i] << ' ';
    cout << endl;
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
