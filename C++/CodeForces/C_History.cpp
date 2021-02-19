
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl


void _run()
{
    int n;
    cin >> n;
    vector<pair<ll,ll>> in(n);
    ll rightMax = 0;
    for(int i =  0 ; i < n ; i++)
    {
        cin >> in[i].first >> in[i].second;
    }

    sort(in.begin(),in.end());
    rightMax = in[0].second;
    int co = 0;
    for(int i = 1 ; i < n ; i++)
    {   
        if(in[i].second <= rightMax)
            co++;
        else
            rightMax = in[i].second;
    }   

    cout << co << endl;
}


int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
