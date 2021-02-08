#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

// void dfs_cycle_count(int node, int p,vector<vector<int>>& graph, vector<int>& col , vector<int>& par, vector<int>&mark,int & Cy)
// {
//     if(col[node] == 2)
//         return;
    
//     else if(col[node] == 1)
//     {
//         Cy++;
//         int cur = p;
//         mark[cur] = Cy;
//         while(cur != node)
//         {
//             cur = par[cur];
//             mark[cur] = Cy;
//         }
//         return;
//     }

//     col[node] = 1;
//     par[node] = p;

//     for(int i : graph[node])
//         if(i != par[node])
//             dfs_cycle_count(i,node,graph,col,par,mark,Cy);
    
//     col[node] = 2;
//     return;
// }

// int counOddCycles(vector<int>& mark)
// {

//     // for(int i = 1 ; i < mark.size() ; i ++) 
//     //     cout << mark[i] << ' ';
//     // cout << endl;
//     int coodd = 0;
//     for(int i = 1 ; i < mark.size() - 1 ; i ++)
//     {
//         if(mark[i] == mark[i+1] && mark[i] != 0 && mark[i] != mark[i-1])
//         {
//             int co = 1;
//             for(int j = i+1 ; j < mark.size() ; j++)
//             {
//                 if(mark[j] != mark[j-1])
//                     break;
//                 co++;
//             }
//             if(co % 2 != 0)
//                 coodd++;
//             i += co -1;
//         }
//     }
//     return coodd;
// }

bool dfs(int node,int parent, vector<vector<int>>& graph,vector<int>& col,int &odds)
{
    if(col[node] == 1)
        return true;
    col[node]=1;
    for(auto child:graph[node])
        if(child!= parent)
        {
            ++odds;
            if(dfs(child,node,graph,col,odds) == 1)
                return true;
        }
    return false;
}


void _run()
{
    int n,m;
    cin >> n >> m;

    
    int x,y;
    vector<vector<int>> graph(n+1);
    for(int i = 0 ; i  < m ; i++)
    {
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<int> col(n+1,0);//,mark(n+1,0);
    // vector<int> par(n+1);
    // int cyclenumber = 0;
    // int connectedCom =0;

    // for(int i = 1 ; i <= n ; i ++)
    //     if(col[i] == 0)
    //         dfs_cycle_count(i,0,graph,col,par, mark,cyclenumber),connectedCom++;
    
    // int ans = counOddCycles(mark);
    // // cout << ans  << endl;

    // if(ans == connectedCom)
    //     ans = 1;
    // if((n-ans) % 2!= 0)
    //     ans++;
    // cout << ans << endl;

    int toRem = 0;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(col[i] == 0)
        {
            int cnt = 0;
            int sol = dfs(i,0,graph,col,cnt);
            if(sol == 1)
                toRem += (cnt % 2== 1);
        }
    }

    if((n-toRem) % 2 != 0)
        toRem++;
    cout << toRem << endl;
    
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
