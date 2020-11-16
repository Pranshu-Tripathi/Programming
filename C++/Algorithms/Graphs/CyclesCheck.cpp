/*
Algorithm:
    Using DFS and tracking parents. If there is a node on which dfs is bieng implemented,
    then apart from this node and his parent no other node in his list should be visited.
    If found then the graph contains cycle.
*/

#include<bits/stdc++.h>
using namespace std;

int vis[1000001] = {0};

bool dfs(vector<int> gra[],int root, int parent){
    vis[root] = 1;
    for(auto child : gra[root]){
        if(vis[child] == 1 && child != parent){
            return false;
        }else if(vis[child] == 0){
            if(dfs(gra,child,root) == false){
                return false;
            }
        }
    }

    return true;
}

int main(){
    int nodes=1,edges=1;
    cin >> nodes >> edges;
    vector<int> graph[nodes+1];
    int u = 0,v=0;
    for(int i = 0;i < edges;i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << dfs(graph,1,-1);

}