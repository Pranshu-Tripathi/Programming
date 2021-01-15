#include<bits/stdc++.h>
using namespace std;

#define ll long long 

void _run()
{
    int n;
    cin >> n;
    vector<pair<int,int>> costs(n);
    ll initialDif = 0;
    for(int i = 0 ; i < n ; i++)
        cin >> costs[i].first >> costs[i].second, initialDif += costs[i].second;

    if(n == 1)
    {
        cout << (costs[0].first <= 500 ? "A" : "G");
        return;
    }    

    if(initialDif <= 500)
    {
        for(int i = 0; i < n ; i++)
            cout << 'G'<< endl;
        return;
    }
    string ans = "";
    int idx = -1;
    for(int i = 0 ; i < n ; i++)
    {
        
        if(initialDif <= 500)
        {
            idx = i;
            break;
        }
        
        ans += "A";
        initialDif -= costs[i].second + costs[i].first;
    }

    if(idx == -1)
    {
        cout << ans << endl;
        return;
    }
    for(int i = idx; i < n  ; i++)
        ans += "G";
    
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;
    while(test--)
        _run();
    return 0;
}