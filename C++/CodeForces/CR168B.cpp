#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

char grid[1001][1001];
int dx[4] = {-1,0,1,0}; // this array would change if the corner elements are also connected.
int dy[4] = {0,-1,0,1};
bool vis[1001][1001];

bool isValid(int x, int y, int n, int m)
{
    if(x < 0 || x >= n || y < 0 || y >= m )
        return false;
    if(grid[x][y] == 'W')
        return false;
    if(vis[x][y])
        return false;
    return true;
}


void dfs(int x, int y, int n, int m)
{

    vis[x][y] = true;
    //cout << x << ' ' << y <<  endl;
    for(int i = 0 ; i < 4 ; i++)
    {
        if(isValid(x+dx[i],y+dy[i],n,m))
            dfs(x+dx[i],y+dy[i],n,m);
    }
}

void _run()
{
    int n,m;
    cin >> n >> m;
    int fi_x,fi_y;
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'B')  
                fi_x = i, fi_y= j;
        }
    dfs(fi_x,fi_y,n,m);

    //cout << fi_x << ' ' << fi_y << endl;

    // for(int i = 0 ; i < n ; i ++)
    // {
    //     for(int j = 0 ; j < m ; j++)
    //     {
    //         cout << vis[i][j] << ' ';s
    //     }
    //     cout << endl;
    // }
    for(int i = 0 ; i < n ; i ++)
        for(int j = 0 ; j < m ; j ++)
        {
            if(grid[i][j] == 'B' && !vis[i][j])
            {
                cout << "NO" << endl;
                return;
            }
        }


    bool black_found = false;
    bool white_found = false;
    for(int i = 0 ; i < n ; i ++)
    {
        black_found = false;
        white_found = false;
        for(int j = 0 ;  j < m  ;  j++)
        {
            if(grid[i][j] == 'B'  && !black_found)
            {
                black_found = true;
            }
            if(grid[i][j] == 'W' && black_found)
            {
                white_found = true;
            }
            if(grid[i][j] == 'B' & black_found && white_found)
            {
                //cout << i << ' ' << j << endl;
                cout << "NO" << endl;
                return;
            }
        }
    }

    black_found = false;
    white_found = false;

    for(int i = 0 ; i < m ; i ++)
    {
        black_found = false;
        white_found = false;
        for(int j = 0 ;  j < n  ;  j++)
        {
            if(grid[j][i] == 'B'  && !black_found)
            {
                black_found = true;
                //cout << j << ' ' << i << endl;
            }
            if(grid[j][i] == 'W' && black_found)
            {
                white_found = true;
                //cout << j << ' ' << i << endl;
            }
            if(grid[j][i] == 'B' & black_found && white_found)
            {
                cout << "NO" << endl;
                return;
            }
        }
    }


    vector<pair<int,int>> inter(n);
    for(int i = 0 ; i < n ; i ++)
    {
        black_found = false;
        int x = 0,y = 0;
        for(int j = 0 ;  j < n ; j ++)
        {
            if(grid[i][j] == 'B' && !black_found)
                x = j,y = j, black_found = true;
            else if(grid[i][j] == 'B')
                y = j;
        }

        inter[i] = {x,y};
    }


    pair<int,int> commonInterval = inter[0];

    for(int i = 1 ; i < n ; i ++)
    {
        if(inter[i].first > commonInterval.second  || inter[i].second < commonInterval.first)
        {
            cout << "NO" << endl;
            return;
        }
        else if(inter[i].first > commonInterval.first && inter[i].second < commonInterval.second)
        {
            commonInterval = inter[i];
        }
    }

    vector<pair<int,int>> inter_col(m);
    for(int i = 0 ; i < m ; i ++)
    {
        black_found = false;
        int x = 0,y = 0;
        for(int j = 0 ;  j < n ; j ++)
        {
            if(grid[j][i] == 'B' && !black_found)
                x = j,y = j, black_found = true;
            else if(grid[j][i] == 'B')
                y = j;
        }

        inter_col[i] = {x,y};
    }

    // for(int i = 0 ; i < m ; i ++)
    //     cout << inter_col[i].first << ' ' << inter_col[i].second << endl;

    pair<int,int> commonIntervalC = inter_col[0];

    for(int i = 1 ; i < m ; i ++)
    {
        if(inter_col[i].first > commonIntervalC.second  || inter_col[i].second < commonIntervalC.first)
        {
            cout << "NO" << endl;
            return;
        }
        else if(inter_col[i].first > commonIntervalC.first && inter_col[i].second < commonIntervalC.second)
        {
            commonIntervalC = inter_col[i];
        }
    }

    

    cout << "YES" << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
