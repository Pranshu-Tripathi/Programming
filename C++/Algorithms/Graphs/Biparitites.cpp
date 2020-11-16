/*
Definition:
    The set of vertices can be seperated into 2 disjoint sets such that:
        1. There is no edge between element of the same set
        2. The edges are always interset.

Construction:
    If color of the parent is 1 then the color of all the children is 0
Checking :
    If at any moment the parent and child have the same color then it is not a bipartite graph.        
*/

#include<bits/stdc++.h>
using namespace std;



int vis[100001] = {0};
int col[100001] = {0};

bool dfs(vector<int> g[],int root,int colour){

    vis[root] = 1;
    col[root] = colour;
    for(auto child : g[root]){
        if(vis[child] == 0){
            if(dfs(g,child,colour^1) == false){
                return false;
            }
        }else if(col[child] == col[root]){
            return false;
        }
    }
    return true;
}

int main(){
    int nodes = 0 , edges = 0;
    cin >> nodes >> edges;
    vector<int> graph[nodes+1];
    int u = 1,v=1;
    for(int i = 0 ; i < edges ; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int root = 1;
    col[root] = 0;
    cout << dfs(graph,root,col[root]);
    

}

