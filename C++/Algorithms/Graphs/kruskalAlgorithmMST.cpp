/*
MST - Minimum spanning tree. This is the tree drawn on a weighted graph such that all the componets are connected
in minimum cost;

Algorithm uses disjount set union logic and greedy approach 

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
#define And &&
#define Or ||



int parent(int u,vector<int>& par)
{
    while(par[u] != u)
        u = par[u];
    return u;
}

void merge(int u,int v, vector<int>& par,vector<int>& siz)
{
    if(siz[u] < siz[v])
    {
        swap(u,v);
    }
    int leader_v = parent(v,par);
    par[leader_v] = u;
    siz[u] += siz[leader_v];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n ,m;
    cin >> n >> m;
    vector<pair<int,pair<int,int>>> edges;
    vector<int> par(n+1);
    vector<int> siz(n+1,1);
    for(int i = 1 ; i <= n ; i++)
        par[i] = i;
    while(m--)
    {
        int u,v,w;
        cin >> u >> v >> w;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    ll ans = 0;
    for(int i = 0 ; i < edges.size() ; i++)
    {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int leader_u = parent(u,par);
        int leader_v = parent(v,par);
        if(leader_u != leader_v)
        {
            ans += w;
            merge(leader_u,leader_v,par,siz);
        }
    }
    cout << ans << endl;
}