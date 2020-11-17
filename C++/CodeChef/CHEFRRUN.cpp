#include<bits/stdc++.h>
using namespace std;

vector<int> graph[100001];
vector<int> trans[100001];
vector<bool> vis(100001);
vector<int> order,SCC;
vector<int> value(100001);



void dfs(int src)
{
    vis[src] = true;
    for(int child :  graph[src])
        if(!vis[src])
            dfs(child);

    order.push_back(src);
    cout << src ;
}

void dfs1(int src)
{
    vis[src] = true;
    for(int child : trans[src])
        if(!vis[child])
            dfs1(child);
    SCC.push_back(src);
}

void run_testcase()
{
    int n;
    cin >> n;


   
    for(int i =0 ; i< n ; i++)
        graph[i].clear(),trans[i].clear(),order.clear(),cin >> value[i];
    
    for(int i = 1 ; i <= n ; i++)
    {
        int a = i-1;
        int b = (i-1 + value[i-1] + 1) % n;
        graph[a].push_back(b);
        trans[b].push_back(a);
    }

    for(int i = 0 ; i < n ; i++)
    {
        cout << i << " : ";
        for(int j : graph[i])
            cout << j << " ";
        cout << endl;
    }

    for(int i = 0 ; i < n ; i++)
    {
        cout << i << " : ";
        for(int j : trans[i])
            cout << j << " ";
        cout << endl;
    }

    for (int i = 0; i < n; i++)
        if(!vis[i])
            dfs(i);

    
    reverse(order.begin(), order.end());

    for(int i = 0; i < n ; i++)
        vis[i] = false;

    

    for(int i = 0 ; i < n ; i++)
        cout << order[i] << " ";
    cout << endl;

    int res = 0;
    for(int element : order)
        if(!vis[element])
        {
            SCC.clear();
            dfs1(element);
            if(SCC.size() == 0 && (SCC[0] != trans[SCC[0]][0]))
                continue;
            res += SCC.size();
        }
    
    //cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int test;
    cin >> test;
    while(test--)
        run_testcase();
    return 0;
}