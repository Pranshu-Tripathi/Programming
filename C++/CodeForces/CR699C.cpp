#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

const string yes = "YES";
const string  no = "NO";

void _run()
{
    int n,m;
    cin >> n >> m;
    int a[n+1],b[n+1],c[m+1];
    vector<int> cola(n+1,-1);
    vector<vector<int>> col(n+1);
    vector<int> ans(m+1,-1);
    a[0] = b[0] = c[0] = -1;

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> b[i];
        cola[b[i]] = i;
    }

    vector<int> pos;

    for(int i = 1 ; i <= n ; i++)
    {
        if(a[i] != b[i])
            pos.push_back(i);
    }

    for(int i = 1 ; i <= m ; i ++)
    {
        cin >> c[i];
        col[c[i]].push_back(i); 
    }

    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     cout << i << ':';
    //     for(int j : col[i])
    //         cout << j <<' ';
    //     cout << endl;
    // }
    if(pos.size() != 0)
    {
        for(int i = pos.size() - 1 ; i >= 0 ; i--)
        {
            if(col[b[pos[i]]].size() == 0)
            {
                cout << no << endl;
                return;
            }
            else
            {
                int n = col[b[pos[i]]].size();
                ans[col[b[pos[i]]][n-1]] = pos[i];
                col[b[pos[i]]].erase(col[b[pos[i]]].end() - 1);
            }
        }

        for(int i = m - 1 ; i >= 1 ; i--)
        {
            if(ans[i] == -1)
                ans[i] = ans[i+1];
        }

        // for(int i : cola)
        //     cout << i << ' ';
        // cout << endl;
        for(int i = m ; i >= 1 ; i--)
        {
            if(ans[i] == -1)
            {
                if(cola[c[i]] == -1)
                {
                    cout << no << endl;
                    return;
                }
                else
                {
                    ans[i] = cola[c[i]];
                }
                
            }
        }

        cout << yes << endl;
        for(int i = 1 ;  i <= m ; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    else
    {
        if(cola[c[m]] == -1)
        {
            cout << no  << endl;
            return;
        }
        else
        {
            cout << yes << endl;
            for(int i = 1 ; i <= m ; i++)
            {
                ans[i] = cola[c[i]];
            }
            for(int i = m - 1 ; i >= 1 ; i--)
            {
                if(ans[i] == -1)
                    ans[i] = ans[i+1];
            }

            for(int i = 1; i <= m ; i++)
            {
                cout << ans[i] << ' ';
            }
            cout << endl;
        }
    }
}

int main()
{
    fast;
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
