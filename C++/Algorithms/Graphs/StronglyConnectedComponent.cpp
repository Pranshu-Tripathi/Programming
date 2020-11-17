/*
Strongly connected components a.k.a scc is defined only for directed graphs.

scc is a subset c of all the vertices such that for any element u,v in c
    there exists a path (u -> v) and (v -> u).

Note :
    1. Graph and Transposed Graph Both Have same ssc.
    2. Condensation Graph
    3. Acyclic Property of Condensation Graph
    4. out[C_i] > out[C_j] in condensation Graph so it contains the edge from C_i ->C_j

    A Directed Acyclic Graph has atleast one node with indegree 0.

    Condensation Graph  is DAG.


    Steps :
        1. Make Graph and Transpose Graph
        2. order array stores the increasing order of out nodes
        3. from the reverse order nodes run dfs on transpose and make fill SCC
*/

#include<bits/stdc++.h>
using namespace std;

void dfs1(int src, vector<int> *trans, vector<int>& SCC, vector<bool>& vis)
{
    vis[src] = true;
    
    for(int child : trans[src])
        if(!vis[child])
            dfs1(child,trans,SCC,vis);
    
    SCC.push_back(src);
}

void dfs(int src, vector<int> *graph, vector<bool>& vis, vector<int> & order)
{
    vis[src] = true;
    
    for(int child : graph[src])
        if(!vis[child])
            dfs(child,graph,vis,order);
    
    order.push_back(src);
}

void run_testcase()
{
    int n,m,a,b;
    cin >> n >> m;
    vector<int> graph[n+1];
    vector<int> trans[n+1];
    vector<bool> vis(n+1,false);
    vector<int> order;
    vector<int> SCC;
    while(m--)
        cin >> a >> b, graph[a].push_back(b), trans[b].push_back(a);

    cout << "Graph and Transpose Initialized \n";    

    for(int i = 1; i <= n ; i++)
        if(!vis[i])
            dfs(i,graph,vis,order);
    
    cout << "Order : ";
    for(int x : order)
        cout << x << " ";
    cout << endl;

    for(int i = 1 ; i <=n ; i++)
        vis[i] = false;

    cout << "VISITED CLEARED\n";

    for(int i = order.size() - 1; i > 0 ; i--)
        if(!vis[order[i]])
        {
            SCC.clear();
            cout << "dfs1 called from : " << i << endl;
            dfs1(order[i],trans,SCC,vis);
            cout << "SCC : ";
            for(int element : SCC)
                cout << element << " ";
            cout << endl;
        }
}

int main()
{
    int test;
    cin >> test;
    while(test--)
        run_testcase();
    return 0;
}