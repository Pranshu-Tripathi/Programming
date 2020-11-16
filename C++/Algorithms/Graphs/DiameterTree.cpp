/*
Longest Path between any two nodes of a tree is known as the diameter of the tree.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> graph[10001];
int vis[10001] = {0};
int maxD,maxN;

void dfs(int node, int dis)
{   
    
    vis[node] = 1;
    if(maxD < dis) 
    {   maxD = dis;
        maxN = node;
       
    }
    for(int child : graph[node])
    {
        
        if(vis[child] == 0)
        {
            dfs(child,dis+1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int u = 0,v =0;
    for(int i =0 ; i < n-1 ; i++)
    {   
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    maxD = maxN = -1;
    dfs(1,0);

    for(int i = 0; i<= n;i++){
        vis[i] = 0;
    }
    maxD = -1;
    dfs(maxN,0);

    cout << maxD;

}