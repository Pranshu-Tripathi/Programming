/*

Sandro is a well organised person.
Every day he makes a list of things which need to be done and enumerates them from 1 to n. 
However, some things need to be done before others. In this task you have to find out whether Sandro can solve all his duties and if so, print the correct order.

Input

In the first line you are given an integer n and m (1<=n<=10000, 1<=m<=1000000). 
On the next m lines there are two distinct integers x and y, (1<=x,y<=10000) describing that job x needs to be done before job y.

Output

Print "Sandro fails." if Sandro cannot complete all his duties on the list. If there is a solution print the correct ordering, the jobs to be done separated by a whitespace. 
If there are multiple solutions print the one, whose first number is smallest, if there are still multiple solutions, print the one whose second number is smallest, and so on.

Spoj Problem
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
        for(int res : result)
        {
            cout << res << " ";
        }
    }
    else
    {
        cout << "Sandro fails.";
    }
    
}