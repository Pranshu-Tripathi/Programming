#include<bits/stdc++.h>
using namespace std;
string suspect = "Suspicious bugs found!";
string clear = "No suspicious bugs found!";
int vis[1000001] = {0};
int col[1000001] = {0};

bool dfs(vector<int> graph[],int root,int clr){
    vis[root] = 1;
    col[root] = clr;
    for(auto child : graph[root]){
        if(vis[child] == 0){
            if(dfs(graph,child,clr^1)==false){
                return false;
            }
        }else if(col[root] == col[child]){
                return false;
        }
    }
    return true;
}

void solve(){
    int bugs=1,interactions = 1;
    cin >> bugs >> interactions;
    int u=0,v=0;
    vector<int>graph[bugs+1];
    for(int i = 0;i < interactions;i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    bool flag = true;
    for(int root = 1 ; root <=bugs;root++){
        if(vis[root] == 0){
            if(dfs(graph,root,0)==false){
                flag = false;
            }
        }
    }
    if(flag){
        cout << clear << endl;
    }else{
        cout << suspect << endl;
    }

}

int main(){
    int test;
    cin >> test;
    string scenario = "Scenario";
    for (int i = 1; i <= test; i++)
    {
        memset(vis,0,sizeof(vis));
        memset(col,0,sizeof(col));
        cout << scenario << " #"<<i<<":\n";
        solve();
    }
    
}