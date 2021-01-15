#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n,m,k;
    cin >> n >> m >> k;
    int bits[n];
    int army[m];
    for(int i = 0 ; i < m ; i++)
        cin >> army[i];
    
    int fedro;
    cin >> fedro;
    int fre = 0;
    for(int i = 0 ; i < m ; i++)
    {
        int x = army[i] ^ fedro;
        int cnt = 0;
        while(x != 0)
        {
            cnt++;
            x = x & (x-1);
        }
        if(cnt <= k)
            fre++;
    }
    cout << fre << endl;
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
