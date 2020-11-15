/*
E. Bertown roads

Bertown has n junctions and m bidirectional roads. We know that one can get from any junction to any other one by the existing roads.

As there were more and more cars in the city, traffic jams started to pose real problems. 
To deal with them the government decided to make the traffic one-directional on all the roads, thus easing down the traffic. 
Your task is to determine whether there is a way to make the traffic one-directional so that there still is the possibility to get from any junction to any other one. 
If the answer is positive, you should also find one of the possible ways to orient the roads.

Input
    The first line contains two space-separated integers n and m (2 ≤ n ≤ 105, n - 1 ≤ m ≤ 3·105) which represent the number of junctions and the roads in the town correspondingly. 
    Then follow m lines, each containing two numbers which describe the roads in the city. Each road is determined by two integers ai and bi (1 ≤ ai, bi ≤ n, ai ≠ bi) — 
    the numbers of junctions it connects.

It is guaranteed that one can get from any junction to any other one along the existing bidirectional roads. 
Each road connects different junctions, there is no more than one road between each pair of junctions.

    Output
If there's no solution, print the single number 0. Otherwise, print m lines each containing two integers pi and qi — each road's orientation.
That is the traffic flow will move along a one-directional road from junction pi to junction qi. You can print the roads in any order. 
If there are several solutions to that problem, print any of them.

*/

#include <bits/stdc++.h>
using namespace std;

bool bridge_exists;
int timer;
void dfs(int curr, vector<int> graph[], vector<bool>& vis, vector<int>& low, vector<int>& in, int par, vector<pair<int,int>>&final_graph)
{
    vis[curr] = true;
    in[curr] = low[curr] = timer;
    timer++;

    for(auto relation : graph[curr])
    {
        if(relation == par) continue;
        if(vis[relation])
        {
            low[curr] = min(low[curr],in[relation]);
            if(in[curr] > in[relation])
            {
                final_graph.push_back({curr,relation});
            }
        }
        else
        {
            dfs(relation,graph,vis,low,in,curr,final_graph);

            if(low[relation] > in[curr])
            {
                bridge_exists = true;
                return;
            }

            final_graph.push_back({curr,relation});
            low[curr] = min(low[curr],low[relation]);
            
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
    vector<pair<int,int>> final_graph;
    while (m--)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1,graph,vis,low,in,-1,final_graph);

    if(bridge_exists)
    {
        cout << 0;
    }
    else
    {
        for(pair<int,int> x : final_graph)
        {
            cout << x.first << " " << x.second << endl;
        }
    }
    
    
}