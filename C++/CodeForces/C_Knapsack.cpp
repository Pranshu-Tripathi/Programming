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
    int n;
    ll W;
    cin >> n >> W;
    vector<pair<ll,int>> w(n);
    int idx3 = -1;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> w[i].first,w[i].second = i+1;
        if(w[i].first >= ceil(W/2.0) && w[i].first <= W)
            idx3 = w[i].second;
    }
        
    sort(w.begin(),w.end());
    int idx = -1;
    int idx2 = -1;
    ll sum = 0;

    for(int i = 0 ; i < n ; i++)
    {
        sum += w[i].first;
        if(sum >= ceil(W/2.0) && sum <= W)
        {
            idx = i;
            break;
        }
    }
    sum = 0;
    for(int i = n - 1 ; i >= 0 ; i--)
    {   
        sum += w[i].first;
        if(sum >= ceil(W/2.0) && sum <= W)
        {
            idx2 = i;
            break;
        }
    }
    if(idx == -1 && idx2 == -1 && idx3 == -1)
        cout << idx << endl;
    else
    {
        if(idx != -1)
        {
            cout << idx + 1 << endl;
            for(int i = 0 ; i <= idx ; i++)
                cout << w[i].second << ' ';
            cout << endl;
        }
        else if(idx2 != -1)
        {
            cout  << n - idx2 << endl;
            for(int  i = n - 1 ; i >= idx2 ; i--)
                cout << w[i].second << ' ';
            cout << endl;
        }
        else if(idx3 != -1)
        {
            cout << 1 << endl;
            cout << idx3 << endl;
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
