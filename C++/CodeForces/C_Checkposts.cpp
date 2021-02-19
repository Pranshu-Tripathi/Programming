#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define mod 1000000007
void dfs(int node, vector<int> * graph, vector<bool>& vis, vector<int>& order)
{
    vis[node] = true;
    for(int child : graph[node])
        if(!vis[child])
            dfs(child,graph,vis,order);
    order.push_back(node);
}
void dfs1(int node, vector<int>* trans, vector<bool>& vis, vector<int>& pr,vector<int>& SCC)
{
    vis[node] = true;
    for(int child : trans[node])
        if(!vis[child])
            dfs1(child,trans,vis,pr,SCC);
    SCC.push_back(pr[node]);
}
void _run()
{
    int n;
    cin >> n;   
    vector<int> pr(n+1);
    for(int i = 1; i <= n ; i++)
        cin >> pr[i];
    vector<int> graph[n+1];
    vector<int> trans[n+1];
    vector<bool> vis(n+1,false);
    vector<int> order;
    vector<int> SCC;
    int m;
    cin >> m;
    int node1,node2;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> node1 >> node2;
        graph[node1].push_back(node2);
        trans[node2].push_back(node1);
    }
    for(int i = 1 ; i <= n ; i++)
        if(!vis[i])
            dfs(i,graph,vis,order);
    for(int i = 1 ;  i <= n ; i++)
        vis[i] = false;
    ll miPri = 0;
    ll co = 1;
    for(int i = order.size() - 1 ; i  >= 0 ; i--)
    {
        if(!vis[order[i]])
        {
            SCC.clear();
            dfs1(order[i],trans,vis,pr,SCC);
            int ele = 0;
            int mele = *min_element(SCC.begin(),SCC.end());
            for(int element : SCC)
                if(element == mele)
                    ele++;
            miPri += mele;
            co = (co % mod * ele % mod) % mod;
        }
    }
    cout << miPri << ' ' << co;
}
int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
