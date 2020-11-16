/*
Vice City is built over a group of islands, with bridges connecting them. 
As anyone in Vice City knows, the biggest fear of vice-citiers is that some day the islands will submerge. 
The big problem with this is that once the islands submerge, some of the other islands could get disconnected. 
You have been hired by the mayor of Vice city to tell him how many islands, when submerged, will disconnect parts of Vice City. 
You should know that initially all the islands of the city are connected.

Input
The input will consist of a series of test cases. 
Each test case will start with the number N (1 ≤ N ≤ 10^4) of islands, and the number M of bridges (1 ≤ M ≤ 10^5). 
Following there will be M lines each describing a bridge. 
Each of these M lines will contain two integers Ui, Vi (1 ≤ Ui,Vi ≤ N), indicating that there is a bridge connecting islands Ui and Vi. 
The input ends with a case where N = M = 0.

Output
For each case on the input you must print a line indicating the number of islands that, when submerged, will disconnect parts of the city.

Spoj Problem
*/

#include <bits/stdc++.h>
using namespace std;

int timer;
set<int> cnt;

void isCutVertex(int curr)
{
    cnt.insert(curr);
}

void dfs(int curr, vector<int> graph[], vector<bool>&vis, vector<int>&low, vector<int>&in,int par)
{
    vis[curr] = true;
    low[curr] = in[curr] = timer++;

    int children = 0;

    for(int relation : graph[curr])
    {
        if(relation == par)
            continue;
        if(vis[relation])
            low[curr] = min(low[curr],in[relation]);
        else
        {
            dfs(relation,graph,vis,low,in,curr);
            low[curr] = min(low[curr],low[relation]);
            if(low[relation] >= in[curr] && par != -1)
                isCutVertex(curr);
            children++;
        }
    }
    if(par == -1 && children > 1)
        isCutVertex(curr);
}

void valid_testcase(int n, int m)
{
    timer = 0;
    cnt.clear();
    int u,v;
    vector<int> graph[n+1];
    vector<int> low(n+1);
    vector<int> in(n+1);
    vector<bool> vis (n+1,false);

    while(m--)
        cin >> u >> v, graph[u].push_back(v), graph[v].push_back(u);
    
    dfs(1,graph,vis,low,in,-1);

    cout << cnt.size() << endl;

}

int main()
{
    int n,m;
    while(true)
    {
        cin >> n >> m;
        if(n == 0 && m == 0)
            break;
        
        valid_testcase(n,m);
    }
}