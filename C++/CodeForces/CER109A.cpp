#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n,d;
    cin >> n >> d;
    int a[n];
    for(int i = 0 ;i  < n ; i++)
        cin >> a[i];
    sort(a,a+n);
    if(a[n-1] <= d)
    {
        cout << "YES" << endl;
        return;
    }
    if(a[0] + a[1] <= d)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
