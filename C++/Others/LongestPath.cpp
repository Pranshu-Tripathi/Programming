#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<long long> adj[] , int u,int v){
    adj[u].push_back(v);
}

void dfs(int root, vector<long long> adj[],long long dp[], bool vis[]){
    vis[root] = true;
    if(adj[root].size() > 0){
        for(auto child : adj[root]){
            if(!vis[child]){
                dfs(child,adj,dp,vis);   
            }
            dp[root] = max(dp[root],1+dp[child]);
        }
    }
}

void findLongestPath(vector<long long> adj[] , int Nodes, int Edges){

    bool vis[Nodes+1];
    memset(vis,false,sizeof(vis));
    long long dp[Nodes+1];
    memset(dp,0,sizeof(dp));
    
    for(int i = 1; i <= Nodes; i++){
        if(!vis[i]){
            dfs(i,adj,dp,vis);
        }
    }
    
    long long ans = 0;

    for(int i = 0 ; i <= Nodes ; i++){
        ans = max(ans,dp[i]);
        //cout << dp[i] << " ";
    }
    
    // for(int i = 0 ; i <= Nodes ; i++){
    //         cout << vis[i] << " " << dp[i] <<endl;
    // }
    cout << ans << endl;

}

int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N,M;
    cin >> N >> M;

    int u[N];
    int v[N];
    try
    {
        vector <long long> adj[N+1];
        for(int i = 0 ; i < M ; i++){
        cin >> u[i] >> v[i];
        addEdge(adj,u[i],v[i]);
        }
    // for(int i = 1 ; i <= N ; i++){
    //     cout << i <<" : " ;
    //     for(int j = 0 ; j < adj[i].size();j++){
    //         cout << adj[i][j] << " " ;
    //     }
    //     cout << endl;
    // }
        findLongestPath(adj,N,M);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << e.what() << endl;
    }
    
    

    
    
}