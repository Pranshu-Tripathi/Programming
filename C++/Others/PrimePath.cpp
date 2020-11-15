/*
    Statement :
        Given two prime numbers A and B, you can change any one digit of A into another such that A still 
        remains prime. Find total operations needed to convert the number A into B
    Algorithm :
        BFS.
*/

#include <bits/stdc++.h>
using namespace std;

vector <int> arr[100001];
vector <int> primes;

int dist[100001],vis[100001];

bool isPrime(int i)
{
    for(int x = 2 ; x * x <= i ; x++)
    {
        if(i % x == 0)  return false;
    }
    return true;
}

bool isValid(int a, int b)
{
    int count = 0;
    while(a != 0 && b != 0)
    {
        if(a%10 != b%10)    count++;

        a /= 10 , b /= 10;
    }
    if(count == 1)  return true;
    else return false;
}

void BuildGraph()
{
    for(int i = 1000; i <= 9999 ; i++)
    {
        if(isPrime(i))
        {
            primes.push_back(i);
        }
    }

    for(int i =  0 ;  i < primes.size() ; i++)
    {
        for(int j = i+1 ; j < primes.size() ; j++)
        {
            int a = primes[i];
            int b = primes[j];
            if(isValid(a,b))
            {
                arr[a].push_back(b);
                arr[b].push_back(a);
            }
        }
    }
}

void bfs(int src)
{
    dist[src] = 0;
    vis[src] = 1;
    queue <int> q;
    q.push(src);
    while(!q.empty())
    {
        int root = q.front();
        q.pop();
        for(int x : arr[root])
        {
            if(vis[x] == 0)
            {
                q.push(x);
                dist[x] = dist[root] + 1;
                vis[x] = 1;
            }
        }
    }
}

int main()
{
    int test,a,b;
    cin >> test;
    BuildGraph();
    while(test--)
    {
        cin >> a >> b;
        for(int i = 0; i < 10000 ; i++)    dist[i] = -1 , vis[i] = 0;
        bfs(a);

        if(dist[b] == -1)
        {
            cout << "Impossible" << endl;
        }
        else
        {
            cout << dist[b] << endl;
        }
        
    }
}