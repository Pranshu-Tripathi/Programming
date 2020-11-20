#include<bits/stdc++.h>
using namespace std;

void bfs(int src, vector<int> * graph, vector<bool>& vis, vector<int>& dist, vector<int>& pred)
{
    
    vis[src] = true;
    dist[src] = 1;
    pred[src] = -1;
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
                pred[child] = curr;
                dist[child] = dist[curr] + 1;
                q.push(child);
            }
        }
    }
}

void run_testcase()
{
    int n,m,a,b;
    cin >> n >>m;
    vector<int> graph[n+1];
    vector<bool> vis(n+1,false);
    vector<int> dist(n+1,-1);
    vector<int> pred(n+1);
    vector<int> path;

    while(m--)
        cin >> a >> b, graph[a].push_back(b), graph[b].push_back(a);
    
    

    bfs(1,graph,vis,dist,pred);


    if(!vis[n])
    {
        cout << "IMPOSSIBLE\n";
        return;
    }
    
    cout << dist[n] << endl;

    path.push_back(n);
    int parent = pred[n];
    while(parent != -1)
    {
        path.push_back(parent);
        parent = pred[parent];
    }

    reverse(path.begin(), path.end());

    for(int p : path)
        cout << p << " ";
    cout << endl;

    return;
}

int main()
{
    int test = 1;
    while(test--)
        run_testcase();
    return 0;
}