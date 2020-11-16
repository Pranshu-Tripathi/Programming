/*
a.k.a cut vertex is a vertex that when removed from the graph increases the number of connected components of the graph.

Some Conclusions :
    1. End point of the bridge that has atleast a degree of 2 is a articulation point.
    2. Articulation point should not necesarily connected to bridges.
    3.Finding Bridge algorithm cannot be used to find the articulation point.



*/



#include <bits/stdc++.h>
using namespace std;

int timer;

void isCutVertex(int curr)
{
    cout << "Articulation Point : " << curr << endl;
}

void dfs(int curr, vector<int> graph[], vector<bool>&vis, vector<int>&low, vector<int>&in,int par)
{
    vis[curr] = true;
    in[curr] = low[curr] = timer;
    timer++;

    int children = 0; // used only for the root node.

    for(auto relation : graph[curr])
    {
        if(relation == par) continue;
        if(vis[relation])
        {
            low[curr] = min( low[curr], in[relation]);
        }
        else
        {
            dfs(relation,graph,vis,low,in,curr);
            low[curr] = min(low[curr],low[relation]);
            if(low[relation] >= in[curr] && par != -1)  
                isCutVertex(curr);
            children++;
        }   
    }

    if(par == -1 && children > 1)     // for the root node.
        isCutVertex(curr);
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
    cin >> u >> v , graph[u].push_back(v), graph[v].push_back(u);

    dfs(1,graph,vis,low,in,-1);

}