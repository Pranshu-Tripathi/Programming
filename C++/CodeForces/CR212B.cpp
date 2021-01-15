#include<bits/stdc++.h>
using namespace std;
#define ll long long

const string no = "NO";
const string yes = "YES";
void _run()
{
    ll n;
    int m;
    cin >> n >> m;
    ll dirty[m];
    for(int i = 0 ; i < m ; i++)
        cin >> dirty[i];
    
    sort(dirty,dirty+m);

    if(dirty[0] == 1 || dirty[m-1] == n)
    {
        cout << no << endl;
        return;
    }

    int tripplet = 0;
    for(int i = 0 ; i < m - 2 ; i++)
        if(dirty[i] == dirty[i+1] -1 && dirty[i] == dirty[i+2] - 2)
            tripplet++;
    
    if(tripplet)
        cout << no << endl;
    else
        cout << yes << endl;
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
