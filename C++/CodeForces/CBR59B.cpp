#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n,k;
    cin >> n >> k;
    int a[n];
    bool vis[n];
    int sumdig = 0;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i], sumdig += a[i];
    int coins = 0;
    while(sumdig < n * k)
    {
        memset(vis,false,sizeof(vis));
        for(int i = 1 ; i < k ; i ++)
        {
            for(int j = 0 ; j < n ; j ++)
            {
                if(a[j] == i && !vis[j])
                {
                    a[j]++;
                    vis[j] = true;
                    sumdig++;
                    break;
                }
            }
        }

        coins++;
    }

    cout << coins << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
