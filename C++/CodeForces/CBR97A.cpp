#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast ios::sync_with_stdio(false); \
            cin.tie(NULL);

void _run()
{
    int n;
    cin >> n;
    int gift[n+1];
    int reci[n+1];
    for(int i = 1 ; i <= n ; i++)
    {
        cin >> gift[i];
        reci[gift[i]] = i;
    }

    for(int i = 1 ; i <= n ; i++)
        cout << reci[i] << ' ';
}

int main()
{
    fast;
    int test = 1;
    while(test--)
        _run();
    return 0;
}