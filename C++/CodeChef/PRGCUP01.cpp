/*
Logic  -> BFS ON GRIDS
*/

#include<bits/stdc++.h>
using namespace std;

int dist[9][9];
bool vis[9][9];
int dx[8] = {-2,-2,-1,-1,1,1,2,2};
int dy[8] = {-1,1,-2,2,-2,2,-1,1};
pair<int,int> Start,End;

bool isValid(int x,int y)
{
    if(x > 8 || y > 8 || x < 1 || y < 1)
        return false;
    if(vis[x][y])
        return false;
    return true;
}

int getColumns(char x)
{
    return x - 'a' + 1;
}

void bfs(int x, int y)
{
    dist[x][y] = 0;
    vis[x][y] = true;
    queue <pair<int,int>> q;
    q.push({x,y});
    while(!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();

        for(int i = 0 ; i < 8 ; i++)
            if(isValid(currX+dx[i],currY+dy[i]))
            {
                int newX = currX+dx[i];
                int newY = currY+dy[i];

                vis[newX][newY] = true;
                dist[newX][newY] = dist[currX][currY] + 1;
                q.push({newX,newY});   
            }
    }
}

void run_testcase()
{
    char sx,sy;
    cin >> sx >> Start.second >> sy >> End.second;
    Start.first = getColumns(sx);
    End.first = getColumns(sy);

    // cout << "Start : " << Start.first << " " << Start.second << endl;
    // cout << "End : " << End.first << " " << End.second << endl;


    for(int i = 1 ; i <= 8 ; i++)
        for(int j = 1; j <= 8 ; j++)
            vis[i][j] = false;

    bfs(Start.first,Start.second);            
    cout << dist[End.first][End.second] << endl;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    int test;
    cin >> test;

    while(test--)
        run_testcase();
    
    return 0;
}