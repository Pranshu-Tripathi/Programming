#include<bits/stdc++.h>
using namespace std;

int dx[4] = {0,1,0,1};
int dy[4] = {0,0,1,1};

bool isValid2D(int x, int y, vector<string>& grid,int n, int m)
{
    cout << x << " " << y;
    int ones = 0;
    for(int k = 0 ; k < 4 ; k++)
    {
        if(x+dx[k] > n || y + dy[k] > n)
            return false;
        if(grid[x+dx[k]][y+dy[k]] == '1')
            ones++;
    }
    cout << ones << endl;
    if(ones == 3) 
        return true;
    return false;
}

void run_test()
{
    int n,m;
    cin >> n >> m;
    
    vector<string> grid(n);
    int ops = 0;
    vector<pair<int,int>> details;

    for(int i = 0 ; i < n ; i++)
        cin >> grid[i];
    
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(isValid2D(i,j,grid,n,m))
            {
                
                ops++;
                for(int k = 0 ; k < 4 ; k++)
                {
                    if(grid[i+dx[k]][j+dy[k]] == '1')
                    {
                        details.push_back({i+dx[k],j+dy[k]});
                        grid[i+dx[k]][j+dy[k]]  = '0';
                    }
                }
            }
        }
    }

    cout << ops << endl;
    for(int i = 0 ; i < details.size() ; i++)
    {
        if(i % 6 == 0 && i != 0)
            cout << endl;
        cout << details[i].first << " " << details[i].second << " ";
    }
    return;
}


int main()
{
    int test;
    cin >> test;
    while(test--)
        run_test();
    return 0;
}