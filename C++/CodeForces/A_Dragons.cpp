#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double

void _run()
{
    int s,n;
    cin >> s >> n;
    vector<pair<int,int>> dra(n);
    for(int i = 0 ;i < n ; i++)
        cin >> dra[i].first >> dra[i].second;
    sort(dra.begin(),dra.end());
    for(int i = 0 ; i < n ; i++)
    {
        if(s <= dra[i].first)
        {
            cn;
            return;
        }
        else
        {
            s += dra[i].second;
        }
    }
    cy;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
