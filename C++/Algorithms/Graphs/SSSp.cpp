/*
    Single Source Shortest Path on Trees using DFS.

    Logic :- Distance of Child = 1 + Distance of Parent
*/

#include <bits/stdc++.h>
using namespace std;

int dis[100001] = {0};
bool vis[100001] = {false};


void dfs(vector<int> graph[],int root, int dis_till_root){
    vis[root] = true;

    for(auto child : graph[root]){
        if(!vis[child]){
            dis[child] = 1+dis_till_root;
            dfs(graph,child,dis[child]);
        }
    }
}

int main(){
    int nodes,edges = 0,root=1;
    cin >> nodes >> edges;
    cin >> root;
    vector<int> graph[nodes+1];
    int u,v = 0;
    for(int i = 0 ; i < edges ; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(graph,root,0);

    for(int i = 1; i <= nodes ; i++){
        cout << i << " : " << dis[i] << endl;
    }
    
}


