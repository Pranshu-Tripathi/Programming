/*
A Bridge is defined as an edge that when removed disconnects the graph.
More precisely we can say that it increases the numner of connected components on removal.


Logic :-
    1. created an in and low array.
    2. in -> stores the discovery time
    3. low -> stores the earliest reachable node from the ith node as the root of the subtree
    4. low[v] > in[u] for the edge to be a bridge.
*/


#include<bits/stdc++.h>
using namespace std;

int timer;


void dfs(int curr, vector<int> graph[], vector<bool>&vis, vector<int>&low, vector<int>&in,int par)
{
    vis[curr] = true;
    in[curr] = low[curr] = timer;
    timer++;

    for(auto child : graph[curr])
    {
        if(child == par) continue;
        else if(vis[child])
        {
                // this child - curr edge is a back edge.
                low[curr] = min(low[curr],in[child]); 
        }
        else
        {
            // this child - curr edge is a forward edge.
            dfs(child,graph,vis,low,in,curr);
            if(low[child] > in[curr])   cout << curr << " - " << child << " is a bridge \n";

            low[curr] = min(low[curr],low[child]);
        }
    }
}


int main()
{
    int n,m,u,v;
    cin >> n >> m;
    vector<int> graph[n+1];
    vector<int> in(n+1);
    vector<int> low(n+1);
    vector<bool> vis(n+1,false);
    while(m--)
    {
        cin >> u >> v; 
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    dfs(1,graph,vis,low,in,-1);
}
