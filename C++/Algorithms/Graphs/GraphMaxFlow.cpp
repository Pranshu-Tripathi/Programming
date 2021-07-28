/*
    In a network if we label 2 nodes as soruce and sink this is called as flow network

    source => only out edges
    sink => only in edges

    2 conditions :
        flow through each edge should be <= capacity of that edge
        sum of inflow = sum of outflow

    Maximum Flow
        flow of maximum possible value from source to sink
    
    Residual Capacity
        defined for edge = capacity - flow
    

    Step 1 :
        Initialize flow through each edge as 0
    
    Step 2 :
        find an augmenting path from s to t
        path using positive capacity to reach t from s

Edmonds - Karp Algorithm

    implementation of Ford Fulkerson using bfs
    time complecity is (VE^2).

    step 1:
        initialize residdual matrix and mac flow to 0.  
*/

#include<bits/stdc++.h>
using namespace std;


int n;
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& par)
{
    fill(par.begin(),par.end(),-1);
    par[s] = -2;
    queue<pair<int,int>> q;
    q.push({s,INT_MAX});

    while(!q.empty())
    {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for(int next : adj[cur])
        {
            if(par[next] == -1 && capacity[cur][next])
            {
                par[next] = cur;
                int new_flow = min(flow,capacity[cur][next]);
                if(next == t)
                {
                    return new_flow;
                }
                q.push({next,new_flow});
            }
        }
        return 0;
    }
}

int maxflow(int s, int t)
{
    int flow = 0;
    vector<int> par(n);
    int new_flow;

    while(new_flow = bfs(s,t,par))
    {
        flow += new_flow;
        int cur = t;
        while(cur != s)
        {
            int prev = par[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return flow;
}