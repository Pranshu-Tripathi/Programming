/*
Take count of all the dfs calls that are made in the main  function.
*/


#include<bits/stdc++.h>
using namespace std;


 vector<int> vis(100001,0);
void dfs(int root,vector<int> graph[]){

    vis[root] = true;

    for(auto child:graph[root]){
        if(!vis[child]){
            dfs(child,graph);
        }
    }
}


int main(){
    int nodes,edges;
    cin >> nodes >> edges;
    
    vector<int> graph[nodes+1];
   
    int u,v;
    
    for(int i = 0 ; i < edges ; i ++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);    
    }
    int count = 1;
    for(int i = 1; i <=nodes;i++){
        if(!vis[i]){
            dfs(i,graph);
            count++;
        }
    }

    cout << count ;
}