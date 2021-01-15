#include<bits/stdc++.h>
using namespace std;
#define ll long long

int dx[4] = {0,1,-1,0};
int dy[4] = {-1,0,0,1};

bool isvalid(int x,int y, int n , int m, vector<vector<char>>& grid)
{
    if(x >= n || y >= m || x < 0 || y < 0)
        return false;
    
    return grid[x][y] == 'P';
}

void _run()
{
    int n,m;
    cin >> n >> m;
    int PCB = 0;
    int PCA;
    vector<vector<char>> grid(n,vector<char>(m));
    for(int i = 0; i < n ;i++)
        for(int j = 0 ; j < m ; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'P')
                PCB++;
        }
    PCA = PCB;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
        {
            if(grid[i][j] == 'W')
            {
                for(int k = 0 ; k < 4 ; k++)
                    if(isvalid(i + dx[k],j + dy[k],n,m,grid))
                    {
                        grid[i+dx[k]][j+dy[k]] = '.';
                        PCA--;
                        break;
                    }
            }
        }

    cout << PCB-PCA << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;
    while(test--)
        _run();
    return 0;
}