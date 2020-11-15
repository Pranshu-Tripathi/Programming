#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0) , cin.tie(0),cout.tie(0);
#define ll long long
#define endl "\n"
#define And &&
#define Or ||
#define FOR(i,a,b)              for(int i = a; i < b; i++)
#define REV(i,a,b)              for(int i = a; i >= b; i--)
#define FORE(i,a,b)             for(int i = a; i <= b; i++)
#define pii                     pair<int,int>
#define pll                     pair< long long int, long long int> 
typedef 						long double ld;
typedef 						unsigned long long ull;
#define F                       first
#define S                       second
#define pb                      push_back

struct  edge
{
    int source;
    int destination;
    long weight;
};

edge arr[25000001];
int parent[25000001];

bool comp(edge a, edge b)
{
    if (a.weight < b.weight)
        return true;
    return false;
}

int find(int a)
{
    if (parent[a] == -1)
        return a;
    return parent[a] = find(parent[a]);
}

void merge(int a, int b)
{
    parent[a] = b;
}

int final_sum(int y)
{
    int sum_edges = 0;
    int src, dest;
    for (int i = y-1; i >= 1; i--)
    {
        src = find(arr[i].source);
        dest = find(arr[i].destination);
        if (src != dest)
        {
            sum_edges += arr[i].weight;
            merge(src, dest);
        }
    }
    return sum_edges;
}

int main()
{
    
    fast;
    memset(parent, -1, sizeof(parent));
    int i,j,n,d;
    cin >> n >> d;
    int nodes[n][d];
    FOR(i,0,n)
    {
        FOR(j,0,d)
        {
            cin >> nodes[i][j];
        }
    }

    int y = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int wet = 0;
            for (int k = 0; k < d; k++)
            {
                wet += abs(nodes[i][k] - nodes[j][k]);
            }
            arr[y].source = i, arr[y].destination = j, arr[y].weight = wet;
            y++;
        }
    }
    y++;
    sort(arr, arr + y, comp);
     
    

    int sum_edges = final_sum(y);
    
    
    cout << sum_edges << endl;
}
