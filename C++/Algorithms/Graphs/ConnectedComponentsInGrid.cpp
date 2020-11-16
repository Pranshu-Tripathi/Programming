#include<bits/stdc++.h>
using namespace std;

int grid[1001][1001];
bool vis[1001][1001];
int dx[4] = {-1,0,1,0}; // this array would change if the corner elements are also connected.
int dy[4] = {0,-1,0,1};
int cnt;

bool isValid(int x, int y, int n, int m)
{
    if(x < 1 || x > n || y < 1 || y > m )
        return false;
    if(vis[x][y] || grid[x][y] == 0)
        return false;
    return true;
}

void dfs(int x, int y, int n, int m)
{
    vis[x][y] = true;

    for(int i = 0 ; i < 4 ; i++)
    {
        if(isValid(x+dx[i],y+dy[i],n,m))
            dfs(x+dx[i],y+dy[i],n,m);
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <=m ; j++)
        {
            cin >> grid[i][j];
        }
    }

    for(int i = 1; i <= n ; i++)
    {
        for(int j = 1; j <=m ; j++)
        {
            if(!vis[i][j] && grid[i][j] == 1)
            {
                cnt++;
                dfs(i,j,n,m);
            }
        }
    }

    cout << "CC : " << cnt;

}