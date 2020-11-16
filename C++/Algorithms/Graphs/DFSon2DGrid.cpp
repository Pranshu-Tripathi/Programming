#include<bits/stdc++.h>
using namespace std;

int grid[1001][1001];
int dx[4] = {-1,0,1,0}; // this array would change if the corner elements are also connected.
int dy[4] = {0,-1,0,1};
bool vis[1001][1001];

bool isValid(int x, int y, int n)
{
    if(x < 1 || x > n || y < 1 || y > n )
        return false;
    if(vis[x][y])
        return false;
    return true;
}

void dfs(int x, int y, int n)
{
    vis[x][y] = true;

    cout << x << " " << y << endl;

    for(int i = 0 ; i < 4 ; i++)
    {
        if(isValid(x+dx[i],y+dy[i],n))
            dfs(x+dx[i],y+dy[i],n);
    }
}

int main()
{
    int n,m;
    cin >> n >> m;

    dfs(1,1,n);

}