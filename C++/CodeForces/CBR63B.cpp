#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n,m;
    cin >> n >> m;
    int l[m], r[m], t[m], c[m];
    int lmin = __INT_MAX__,rmax = -1;
    for(int i = 0 ; i < m ; i ++)
        cin >> l[i] >> r[i] >> t[i] >> c[i] , lmin = min(lmin,l[i]) , rmax = max(rmax,r[i]);
    
    //cout << lmin << ' ' << rmax << endl;
    int timestamps[m][n+1];
    for(int i = 0 ; i < m ; i ++)
        for(int j = 1 ; j <= n ; j ++)
            timestamps[i][j] = __INT_MAX__;
    int prof = 0;

    for(int i = 0 ; i < m ; i ++)
    {
        for(int pos = lmin ; pos <= rmax ; pos++)
        {
            if(pos < l[i] || pos > r[i])
                continue;
            timestamps[i][pos] = t[i] ;
        }
    }

    for(int i = lmin; i <= rmax ; i++)
    {
        int ti = __INT_MAX__;
        int player = -1;
        for(int j = 0 ; j < m ; j++)
        {
            if(timestamps[j][i] != __INT_MAX__ && ti > timestamps[j][i])
            {
                player = j;
                ti = timestamps[j][i];
            }
        }
        if(player != -1)
        {    
            prof += c[player];
            //cout << prof << ' ' << i << ' ' << player << ' ' << c[player] << endl;
        }
    }

    cout << prof << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
