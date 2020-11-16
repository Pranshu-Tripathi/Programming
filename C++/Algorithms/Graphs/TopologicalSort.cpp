/*
Topological Sort is used when we want to sort depending upon the dependency of one process on the other.
Algorithm used - > Kahn's Algorithm
in degree stores the process that needed to be peformed before the given task
Logic :-
    1. in degree is stored while creating the graph
    2. then the 0 in degree elements are pushed in queue and final answer.
    3. Then they are removed from the graph and all their descendends loose one in degree.
*/

#include <bits/stdc++.h>
using namespace std;

bool kahnTopo(vector<int> graph[], vector<int>& result, vector<int>& inDegree)
{
    priority_queue<int, vector<int> , greater<int>> pq;                    
    /*

    priority queue is used because the topological sort is not unique. 
    To get lexiographically smallest array in result we use priority queue.
    Priority Queue is made using min max heaps. We declared min heap i.e, min element at the top of the heap.
    */
    for(int i = 1; i < inDegree.size() ; i++)
    {
        if(inDegree[i] == 0)
        {
            pq.push(i);
        }
    }

    while(!pq.empty())
    {
        int curr = pq.top();
        pq.pop();
        result.push_back(curr);
        for(int child : graph[curr])
        {
            inDegree[child]--;
            if(inDegree[child] == 0)
                pq.push(child);
        }
    }

    return (result.size() == inDegree.size() - 1);
}

int main()
{
    int n,m,a,b;
    cin >> n >> m;
    vector<int> graph[n+1];
    vector<int> result;
    vector<int> inDegree(n+1,0);
    while(m--)
        cin >> a >> b, graph[a].push_back(b), inDegree[b]++;  // Graph is Directed
    

    if(kahnTopo(graph,result,inDegree))
    {
        cout << "Topological Sort \n";
        for(int res : result)
        {
            cout << res << " ";
        }
    }
    else
    {
        cout << "Not Possible To Sort Topologically";
    }
    
}