#include<bits/stdc++.h>
using namespace std;

bool cycleDirected(vector<int> graph[] , int curr, vector<bool>& vis)
{
    if(vis[curr])
        return true;
    vis[curr] = true;
    for(auto child : graph[curr])
    {
        if(cycleDirected(graph,child,vis))
            return true;
    }
    vis[curr] = false;
    return false;
}

bool checkCycle(vector<int> graph[], int v)
{
    vector<bool> vis(v+1,false);
    for(int i = 1; i <= v ; i++)
    {
        vis[i] = true;
        for(auto child : graph[i])
        {
            if(cycleDirected(graph,child,vis))
                return true;
        }
        vis[i] = false;
    }
    return false;
}


int main()
{
    /*
    create Graph and call function
    */
}