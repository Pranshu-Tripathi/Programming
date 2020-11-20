#include<bits/stdc++.h>
using namespace std;

char grid[1001][1001];
int previousStep[1001][1001];
int dist[1001][1001];
bool vis[1001][1001];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
string paths = "URDL";
vector<int> steps;




bool isValid(int x, int y, int n, int m)
{
    if(x > n || y > m || x < 1 || y < 1)
        return false; 
    if(vis[x][y] || grid[x][y] == '#')
        return false;
    return true;
}

void bfs(pair<int,int>& src, int n, int m)
{
    vis[src.first][src.second] = true;
    dist[src.first][src.second] = 0;
    queue<pair<int,int>> q;
    q.push(src);

    while(!q.empty())
    {
        pair<int,int> curr = q.front();
        q.pop();

        for(int i = 0 ; i < 4 ; i++)
            if(isValid(curr.first+dx[i],curr.second+dy[i],n,m))
            {
                pair<int,int> neighbour = {curr.first+dx[i],curr.second+dy[i]};
                vis[neighbour.first][neighbour.second] = true;
                dist[neighbour.first][neighbour.second] = dist[curr.first][curr.second] + 1;
                previousStep[neighbour.first][neighbour.second] = i;
                q.push(neighbour);
            }
    }
}

void bfs2(pair<int,int> des, pair<int,int> src)
{
    while(des != src)
    {
        int i = previousStep[des.first][des.second];
        steps.push_back(previousStep[des.first][des.second]);
        des = {des.first - dx[i], des.second - dy[i]};
    }   
}

void run_testcase(int n, int m)
{
    pair<int,int> src,des;

    for(int i = 1 ; i <= n; i++)
        for(int j = 1 ; j <= m ; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'A')   src = {i,j};
            if(grid[i][j] == 'B')   des = {i,j};
        }

    bfs(src,n,m);

        
    
    if(vis[des.first][des.second])
    {
        cout << "YES\n";
        cout<< dist[des.first][des.second] << endl;
        bfs2(des,src);
        reverse(steps.begin(),steps.end());
        for(int x : steps)
            cout << paths[x];
        cout <<endl;
        return;
    }
    cout << "NO\n";

}


int main()
{
    int n,m;
    cin >> n >> m;
    run_testcase(n,m);    
}