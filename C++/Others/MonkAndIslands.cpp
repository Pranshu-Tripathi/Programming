/*
Solution Algorithm :
    Apply bfs to find the levels of the graph and then use the difference.
*/

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

vector<int> graph[10001];
int vis[10001] = {0};
int level[10001] = {0};
void BFS(int node)
{
    vis[node] = 1;
    level[node] = 0;
    queue<int> q;
    q.push(node);
    while(!q.empty())
    {
        int root = q.front();
        q.pop();
        for(int child : graph[root])
        {
            if(vis[child] == 0)
            {
                q.push(child);
                vis[child] = 1;
                level[child] = level[root]+1;
            }
        }
    }
}

void solve()
{
    int N,M;
    cin >> N >> M;
    int u,v,i;

    FORE(i,1,N) graph[i].clear();
    FORE(i,1,M) cin >> u >> v, graph[u].pb(v) , graph[v].pb(u);

    BFS(1);

    cout << level[N] << endl;

}


int main()
{
    fast;
    int test;
    cin >> test;
    while(test--)
    {
        memset(vis,0,sizeof(vis));
        memset(level,0,sizeof(level));
        solve();
    }
}