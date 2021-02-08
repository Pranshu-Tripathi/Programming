#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n;
    cin >> n;
    vector<pair<ll,ll>> dates(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> dates[i].first >> dates[i].second;
    }

    sort(dates.begin(),dates.end());

    ll best = -1;
    for(int i = 0 ;i < dates.size() ;++i)
    {
        if(best <= dates[i].second)
            best = dates[i].second;
        else
            best = dates[i].first;
    }

    cout << best << endl;

}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
