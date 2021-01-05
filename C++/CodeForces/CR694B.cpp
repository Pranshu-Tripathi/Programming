#include<bits/stdc++.h>
using namespace std;
#define ll long long

int divposs(int y, int x)
{
    int cnt = 1;
    while(y % x == 0)
    {
        y /= x;
        cnt++;
    }
    return cnt;
}

void _run()
{
    ll n,x;
    cin >> n >> x;
    bool flag = true;
    int index;
    vector<ll> arr(n);
    vector<ll> div(n);
    int miDi = __INT_MAX__;
    for(int i = 0 ; i < n ;i ++)
    {
        
        cin >> arr[i];
        div[i] = divposs(arr[i],x);
        if(miDi > div[i])
        {
            index = i;
            miDi = div[i];
        }
    }
    ll sum = 0;
    for(int i = 0 ; i < n ;i ++)
    {
        if( i < index)
        {
            sum += arr[i] * (miDi + 1);
        }
        else
        {
            sum += arr[i] * miDi;
        }
        
    }

    cout << sum << endl;
    
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
