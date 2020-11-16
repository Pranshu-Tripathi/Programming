/*
Trees have 1 connected component and n-1 edges.
*/

#include<bits/stdc++.h>

using namespace std;

void dfs(vector<int> graph[],int vis[],int root){
    vis[root] = 1;
    for(auto child : graph[root]){
        if(vis[child] == 0){
            dfs(graph,vis,child);
        }
    }
}

int main()
{
    int nodes,edges;
    cin >> nodes >> edges;
    vector<int> graph[nodes+1];
    int vis[nodes+1] = {0};
    int u = 0 , v = 0;
    for(int i = 0 ; i < edges; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int count = 0;
    if(edges != nodes -1){
        cout << "NO";
        return 0;
    }else{
       
        for(int i = 1; i <= nodes ; i++){
            if(vis[i]==0){
                dfs(graph,vis,i);
                count++;
            }
        }
    }

    if(count == 1){
        cout << "YES";
    }else{
        cout << "NO";
    }

}