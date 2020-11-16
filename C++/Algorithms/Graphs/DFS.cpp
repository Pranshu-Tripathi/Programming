#include <bits/stdc++.h>
using namespace std;
#define N 100

void dfs(int root,vector<int> graph[],vector<bool> vis){

    vis[root] = true;

    for(auto child:graph[root]){
        if(!vis[child]){
            dfs(child,graph,vis);
        }
    }


}

int main(){
    //initialize the graph
    int root = 1;
    vector<int> graph[N];
    vector<bool> vis(N,false);
    // take the inputs
    dfs(root,graph,vis);
}