/*
Application:
    To check if one node lies in the sub tree of the other node in o(1) after precomputation.

Logic:
    Apply DFS on nodes. At the current node:
        1. save the intime.
        2.Apply DFS to children.
        3.At the end of the loop save the outtime of the current node.
    
    if node1 lies in the subtree of node2 --> intime[node1] > intime[node2] && outtime[node2] > outtime[node1]
*/

#include<bits/stdc++.h>
using namespace std;

int vis[1000001] = {0};
int intime[1000001] = {0},outtime[1000001] = {0};
int timer = 1;
void dfs(vector<int> g[],int root){
    vis[root] =1;
    intime[root] = timer++;
    for(auto c :g[root]){

        if(vis[c] == 0){
            dfs(g,c);
        }
    }

    outtime[root] = timer++;
}

int main(){
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

    dfs(graph,1);
}