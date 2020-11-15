/*
In a social networking site, people are connected with other people. The whole system appears as a giant connected graph. In this question, you are required to answer the total number of people connected at t nodes away from each other (t distance connectivity). For example: Two persons directly connected are at 1 distance connectivity. While the two persons having a common contact without having direct connectivity, are at 2 distance connectivity.

First line of input line contains, two integers n and e, where n is the nodes and e are the edges. Next e line will contain two integers u and v meaning that node u and node v are connected to each other in undirected fashion. Next line contains single integer, m, which is number of queries. Next m lines, each have two inputs, one as source node and other as a required t distance connectivity which should be used to process query.

 

Note: The index of nodes will be 0-based. The example and the test case shown is of 1-based index. For submitting the solution, use 0-based indexing.
*/

#include<bits/stdc++.h>
using namespace std;

void init(vector<int>& levels, vector<bool>& vis)
{
    for(int i = 0; i < levels.size() ;i++)
    {
        levels[i] = 0;
        vis[i] = false;
    }
}

void bfs(int src, vector<int> graph[],vector<int> & dist, vector<bool> & vis , vector<int>& levels)
{
    dist[src] = 0;
    vis[src] = true;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
        int curr = q.front();
        q.pop();
        for(int child : graph[curr])
        {
            if(!vis[child])
            {
                vis[child] = true;
                dist[child] = dist[curr]+1;
                levels[dist[child]]++;
                q.push(child);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int n,m,a,b,src,d,q;
    cin >> n >> m;
    vector<int> graph[n+1];
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cin >> q;
    vector<int> levels(n+1);
    vector<bool> vis(n+1);
    vector<int> dist(n+1);
    while(q--)
    {
        init(levels,vis);
        cin >> src >> d;
        bfs(src,graph,dist,vis,levels);
        cout << levels[d] << endl;
    }
}