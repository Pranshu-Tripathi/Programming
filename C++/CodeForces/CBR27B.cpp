#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n+1);
    vector<int> seq(n+1);
    int inps = ((n * (n -1 ))/2)  - 1;
    for(int i =1 ;i <= n ; i++)
        seq[i] = i;
    for(int i = 0 ; i <  inps; i++)
    {
        int x,y;
        cin >> x >> y;
        int pos1,pos2;
        for(int i = 1 ; i <= n ; i++)
        {
            if(x == seq[i])
            {
                pos1 = i;
                break;
            }
        }
        for(int i = 1 ; i <= n ; i++)
        {
            if(y == seq[i])
            {
                pos2 = i;
                break;
            }
        }
        if(pos1 > pos2)
        {
            for(int i = pos1 - 1 ; i >= pos2 ; i--)
                swap(seq[i],seq[i+1]);
        }
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<int> missing;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(graph[i].size() != n - 1)
            missing.push_back(i);
    }

    
    for(int i = 1 ; i <= n ; i ++)
    {
        if(seq[i] == missing[0] || seq[i] == missing[1])
            cout << seq[i] << ' ';
    }

    
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
