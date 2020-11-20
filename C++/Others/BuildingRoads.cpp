#include<bits/stdc++.h>
using namespace std;

bool flag;

void dfs(int src,vector<int>* graph, vector<bool>& vis, vector<int>& nodes)
{
    if(!flag)
    {
        flag = !flag;
        nodes.push_back(src);
    }
    vis[src] = true;
    for(int child : graph[src])
        if(!vis[child])
            dfs(child,graph,vis,nodes);
}

void run_testcase()
{
    int n,m,a,b;
    cin >> n >> m;
    vector<bool> vis(n+1,false);
    vector<int> graph[n+1];
    vector<int> nodes;
    for(int i = 0 ; i < m ; i++)
        cin >> a >> b, graph[a].push_back(b), graph[b].push_back(a);
    int cc = 0;
    for(int i =1 ; i <= n; i++)
    {
        if(!vis[i])
            cc++, flag = false, dfs(i,graph,vis,nodes);
    }

    cout << cc - 1 << endl;;
    
    for(int i = 0 ; i < nodes.size() - 1 ; i++)
    {
        cout << nodes[i] <<" " << nodes[i+1] << endl;
    }

}

int main()
{

    ios::sync_with_stdio(0), cin.tie(0);

    int test = 1;
    while(test--)
        run_testcase();
    return 0;

}