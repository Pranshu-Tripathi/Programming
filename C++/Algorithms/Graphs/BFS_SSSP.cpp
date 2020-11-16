/*
Single Source Shortest Path is the code for finding the minimum distance from one node to all other nodes. 

BFS :- logically all the levels are the shortest paths.
*/

#include<bits/stdc++.h>
using namespace std;

void bfs(int root,vector<int> graph[] , vector<int>& levels, vector<bool> & vis)
{
    levels[root] = 0;
    vis[root] = true;
    queue <int> q;
    q.push(root);
    while(!q.empty())
    {
        int oot = q.front();
        q.pop();  
        for(int x : graph[oot])
        {
            if(!vis[x])
            {
                levels[x] = levels[oot] + 1;
                vis[x] = true;
                q.push(x);
            }
        }
         
    }
}


int main()
{

   int n,e;
   cin >> n >> e;
    int root;
    cin >> root;
   vector<int> graph[n+1];
   vector<int> levels(n+1,0);
   vector<bool> vis(n+1,false);
    // graph input
    int x , y;
   for(int i = 0 ; i < e ; i++)
   {
       cin >> x >> y;
       graph[x].push_back(y);
       graph[y].push_back(x);
   } 
   // graph input

   bfs(root,graph,levels,vis);

   for(int i = 1 ; i <= n ; i++)
   {
       cout << i << " : " << levels[i] << endl;
   }
    
}