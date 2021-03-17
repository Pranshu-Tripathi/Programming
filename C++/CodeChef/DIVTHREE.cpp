#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    ll n,k,d;
    cin >> n >> k >> d;
    vector<ll> arr(n);
    ll sum = 0;
    for(int i =0 ; i < n ; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    
    int ans = sum / k;
    if( ans > d)
    {
        cout << d << endl;
        return;
    }

    cout << ans << endl;
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
