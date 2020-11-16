#include<bits/stdc++.h>
using namespace std;

int grid[1001][1001];
int dist[1001][1001];
bool vis[1001][1001];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

bool isValid(int x,int y, int n, int m)
{
    if(x > n || y > m || x < 1 || y < 1)
        return  false;
    if(vis[x][y])
        return false;
    return true;
}

void bfs(int srcX, int srcY,int n, int m)
{
    vis[srcX][srcY] = true;
    dist[srcX][srcY] = 0;
    queue<pair<int,int>> q;
    q.push({srcX,srcY});
    while(!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4 ;i++)
        {
            if(isValid(currX+dx[i],currY + dy[i],n,m))
            {
                 int newX = currX + dx[i];
                 int newY = currY + dy[i];
                 vis[newX][newY] = true;
                 dist[newX][newY] = dist[currX][currY] + 1;
                 q.push({newX,newY});
            }   
        }
    }
}

int main()
{
    int n,m,srcX, srcY;
    cin >> n >> m >> srcX >> srcY;

    bfs(srcX, srcY,n,m);

    for(int i = 1; i <=n ; i++)
    {
        for(int j = 1; j <= m ; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
        
}