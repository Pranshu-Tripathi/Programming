#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n,m;
    cin >> n >> m;
    int a[m];
    for(int i = 0 ; i < m ; i++)
        cin >> a[i];

    int start = 1;
    long long ti = 0;
    for(int i = 0; i < m ; i++)
    {
        if(start <= a[i])
            ti += a[i] - start;
        else
            ti += n + a[i] - start;
        start = a[i];
    }
    cout << ti << endl;
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
