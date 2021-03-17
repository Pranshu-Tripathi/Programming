#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000009

void _run()
{    
    int n,m;
    cin >> n >> m;
    int direction = 1;
    int b = 0;
    char grid[n][m];
    memset(grid,'.',sizeof(grid));
    for(int i = 0 ; i < n ; i+=2)
    {
        if(direction > 0)
        {
            while(b < m)
                grid[i][b] = '#',b += direction;
            if(i < n - 1)
                grid[i+1][b-1] = '#';
            direction = -1;
            b--;
        }
        else
        {
            while(b >= 0)
                grid[i][b] = '#', b += direction;
            if(i < n -1)
                grid[i+1][b+1] = '#';
            direction = 1;
            b++;
        }
    }

    for(int i = 0 ; i < n ; i++) 
    {
        for(int j = 0 ; j < m ;j++)
            cout << grid[i][j];
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
