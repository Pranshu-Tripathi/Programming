#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

bool visx[101];
bool visy[101];

void _run()
{
    int n,m;
    cin >> n >> m;
    cout << min(n,m)+1 << endl;
    visx[0] = visy[m] = true; // included {0,1}
    vector<pair<int,int>> cordi;
    cordi.push_back({0,m});
    for(int x = 1 ; x <= n ; x++)
    {
        for(int y = m ; y >= 0 ; y--)
        {
            if(!visy[y])
            {
                visy[y] = true;
                visx[x] = true;
                cordi.push_back({x,y});
                break;
            }
        }
    }
    for(pair<int,int> p : cordi)
        cout << p.first << ' ' << p.second << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
