#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n;
    cin >> n ;
    int lit[n];
    int sum = 0;
    for(int i = 0 ;  i< n ; i ++)
        cin >> lit[i], sum += lit[i];
    bool nochange = true;
    for(int i = 1  ;i < n ; i ++)
        if(lit[i] != lit[i-1])
            nochange = false;
    
    if(nochange)
    {
        cout << "Exemplary pages.";
        return;
    }

    if(sum % n != 0)
    {
        cout << "Unrecoverable configuration.";
        return;
    }

    int perGlass = sum / n;

    int dif[n];

    vector<int> gls;
    
    for(int i = 0 ; i < n ; i ++)
    {
        dif[i]  = perGlass - lit[i];
        if(dif[i] != 0)
            gls.push_back(i);
    }

    if(gls.size() > 2)
    {
        cout << "Unrecoverable configuration.";
        return;
    }
    
    
    if(lit[gls[0]] < lit[gls[1]])
    {
        cout << abs(perGlass - lit[gls[0]]) << " ml. from cup #" << gls[0] + 1 << " to cup #" << gls[1] + 1 <<".";
    }
    else
    {
        cout << abs(perGlass - lit[gls[0]]) << " ml. from cup #" << gls[1] + 1 << " to cup #" << gls[0] + 1 <<".";
    }

}
int main()
{
    fast;
    int test  = 1;
    while(test--)
        _run();
    return 0;
}
