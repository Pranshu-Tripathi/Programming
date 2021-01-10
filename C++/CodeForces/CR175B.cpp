#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n,s,t;
    cin >> n >> s >> t;
    int pi[n+1];
    for(int i =1 ; i <= n ; i++)
        cin >> pi[i];
    vector<bool> vis(n+1,false);
    vis[s] = true;
    int pos = s;
    int i;
    for( i = 1 ; i <= n ; i++)
    {
        vis[pos] = true;
        if(pos == t)
            break;
        pos = pi[pos];
    }

    if(!vis[t])
        cout << -1 << endl;
    else
        cout << i -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    while(test--)
        _run();
    return 0;
}
