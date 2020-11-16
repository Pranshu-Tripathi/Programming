/*
Calculating the size of the subtree from a root node in 0(n).

Algorithm:
    repetitive call to dfs.
    subtree size of parent is summation of the subtrees of its children.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
int vis[100001] = {0};
int sizeSub[100001] = {0};


int dfs(int node)
{
    vis[node] = 1;
    int curent_size = 1;

    for(auto c : graph[node])
    {
        if(vis[c] == 0)
        {
            curent_size+=dfs(c);
        }
    }
    sizeSub[node] = curent_size;
    return curent_size;
}

int main()
{
    int n,m;
    cin >> n >> m;
    int u,v;
    for(int i = 0 ; i < m ; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int treesize = dfs(1);
}