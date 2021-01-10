#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n,m;
    cin >> n >> m;
    string a,b,c;
    map<string,string> mp;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> a >> b;
        if(a.length() > b.length())
            mp[a] = b;
        else
            mp[a] = a;
    }

    for(int i = 0 ; i< n ; i++)
    {
        cin >> c;
        cout << mp[c] << " ";
    }
    cout << endl;
    return;
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
