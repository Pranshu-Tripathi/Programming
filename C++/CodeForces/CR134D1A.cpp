#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

int n;
int x[110];
int y[110];
bool used[110];

void dfs(int v)
{
    used[v] = true;
    for(int i = 0 ;i < n ; i++)
    {
        if(!used[i])
        {
            if(x[i] == x[v] || y[i] == y[v])   
                dfs(i);
        }
    }
}

void _run()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x[i] >> y [i];
    }

    int c = 0;

    for(int i = 0 ; i < n ; i++)
    {
        if(!used[i])
            dfs(i),
            c++;
    }

    cout << c - 1 << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
