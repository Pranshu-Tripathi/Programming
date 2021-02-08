#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

int n,m,k,cnt = 0;
char grid[502][502];
bool vis[501][501];
int ans[501][501];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

bool isValid(int x, int y)
{
    if(x < 1 || x > n || y < 1 || y > m)
        return false;
    if(vis[x][y] || grid[x][y] == '#')
        return false;
    return true;
}

void dfs(int x,int y, int level)
{
    vis[x][y] = true;
    ans[x][y] = level;
    for(int i = 0 ; i < 4 ; i++)
    {
        if(isValid(x+dx[i],y+dy[i]))
            dfs(x+dx[i],y+dy[i],level+1);
    }
    if(cnt != k)
    {
        cnt++, grid[x][y] = 'X';
    }
}

void _run()
{
    cin >> n >> m >> k;
    int sta,en;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == '.')
                sta = i, en = j;
        }

    dfs(sta,en,1);

    for(int i = 1 ; i <= n ; i++)
    {
        for(int j = 1;  j <=m ; j++)
        {
            cout << grid[i][j];
        }
        cout << endl;
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
