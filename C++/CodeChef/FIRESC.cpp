/*
Connected Components number = number of Fire Exits needed
Product of all the sizes of components = number of captain chosing
*/

#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
int vis[1000001] = {0};
vector<int> graph[1000001];
int node_count;

void dfs(int node){
    vis[node] = 1;
    node_count ++;
    for(auto child : graph[node]){
        if(vis[child] == 0){
            dfs(child);
        }
    }
}


void solve(){   
    for(int i = 0 ; i<=1000000 ; i++){
        vis[i] = 0;
        graph[i].clear(); 
    }

    int nodes = 0,edges=0;
    cin >> nodes >> edges;

    int u = 0,v = 0;
    for(int i = 0 ; i < edges ; i++){
        cin >> u>> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    long long res = 1;
    int count = 0;
    for(int i = 1;i <=nodes;i++){
        if(vis[i] == 0){
            node_count = 0;
            dfs(i);
            count++;
            res = (res * node_count)%m;
        }
    }

    cout << count << " " << res << endl;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}