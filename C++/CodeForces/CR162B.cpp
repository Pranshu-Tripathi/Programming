#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n;
    cin >> n;
    int ht[n];
    ll tim = 0;
    int prh = 0;

    for(int i = 0 ; i < n ; i++)
        cin >> ht[i];
    
    prh = ht[0];
    tim += ht[0] + 1;

    for(int i = 1;  i< n ; i++)
    {
        if(prh < ht[i])
        {
            tim += (ht[i] - prh) + 1 + 1; // one for jump one for eating;
            prh = ht[i];
        }
        else if(prh == ht[i])
        {
            tim += 1 + 1 ;
        }
        else
        {
            //prh > ht[i]
            tim += (prh - ht[i]) + 1 + 1;
            prh = ht[i];
        }
    }

    cout << tim << endl;
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
