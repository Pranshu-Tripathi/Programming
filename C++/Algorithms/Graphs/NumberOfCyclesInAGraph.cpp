#include<bits/stdc++.h>
using namespace std;

void dfs_cycle_count(int node, int p,vector<vector<int>>& graph, vector<int>& col , vector<int>& par, int & Cy)
{
    if(col[node] == 2)
        return;
    
    else if(col[node] == 1)
    {
        Cy++;
        return;
    }

    col[node] = 1;
    par[node] = p;

    for(int i : graph[node])
        if(i != par[node])
            dfs_cycle_count(i,node,graph,col,par,Cy);
    
    col[node] = 2;
    return;
}

int main()
{
    int n,m;
    cin >> n >> m;
    int x,y;
    vector<vector<int>> graph(n+1);
    for(int i = 0 ; i  < m ; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> col(n+1,0);
    vector<int> par(n+1);
    int cyclenumber = 0;

    for(int i = 1 ; i <= n ; i ++)
        if(col[i] == 0)
            dfs_cycle_count(i,0,graph,col,par,cyclenumber);

    cout << cyclenumber << endl;
}