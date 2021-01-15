#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n,m;
    cin >> n >> m;

    int b[n][m];
    int a[n][m];

    memset(a,-1,sizeof(a));
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> b[i][j];
    
    for(int i  = 0 ; i < n ;i ++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(b[i][j] == 0)
            {
                for(int k = 0 ; k < m ; k++)
                    a[i][k] = 0;
                for(int k = 0 ; k < n ; k++)
                    a[k][j] = 0;
            }
        }
    }

    bool backTrack = true;

    for(int  i= 0  ; i< n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {   
            int r = 0;
            for(int k = 0 ; k < n ; k++)
                r = r or a[k][j];
            for(int k = 0 ; k < m ; k++)
                r = r or a[i][k];
            if(b[i][j] != r)
            {
                backTrack = false;
                break;
            }
        }

        if(!backTrack)
            break;
    }

    if(!backTrack)
    {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cout << abs(a[i][j]) << " ";
        }
        cout << endl;
    }    
            
 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    while(test--)
        _run();
    return 0;
}
