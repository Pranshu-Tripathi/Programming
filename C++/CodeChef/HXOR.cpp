#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll getDescimal(vector<vector<ll>> & arr, ll i)
{
    ll val = 0;
    int power = 1;
    for(int j = 0; j < 32 ; j ++)
    {
        val += arr[i][j] * power;
        power *=2;
    }

    return val;
}

void convertBinary(ll i, ll n,vector<vector<ll>>& arr)
{
    int j = 0;
    while(n)
    {
        arr[i][j++] = n % 2;
        n /= 2;
    }
}

void run_testcase()
{
    ll n,x;
    cin >> n >> x;
    vector<vector<ll>> arr(n,vector<ll>(32,0));
    ll num;
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> num;
        convertBinary(i,num,arr);
    }
    int lastBit = arr[n-2][0];
    int secondLastBit = arr[n-1][0];
    vector<int> compute(32,0);
    for( int i = 0 ; i < n ; i ++)
    {
        int j = 31;
        while(j--)
        {
            if(arr[i][j] != 0)
            {
                (compute[j] != 0)?compute[j] = arr[i][j] = 0 : (x != 0 && i != n-1) ? compute[j] = 1,arr[i][j] = 0,x-- : compute[j] = compute[j];
            }
        }
    }
    int j = 31;
    while(j--)
    {
        compute[j] != 0 ? arr[n-1][j] = 1 : arr[n-1][j] = arr[n-1][j];
    }

    if(x%2 && n > 1)
    {
         if(n == 2)
        {
            arr[n-1][0] == 0 ? arr[n-2][0] = arr[n-1][0] = 1: (lastBit == 1 || secondLastBit == 1) ?arr[n-1][0] = 0, arr[n-2][0] = 1: arr[n-1][0] = arr[n-1][0];
        }
    }


    for(ll i = 0 ; i < n ; i++)
    {
        ll ans = 0;
        ans += getDescimal(arr,i);
        cout << ans << " ";
    }

    cout << endl;
    return;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin >> test;
    while(test--)
        run_testcase();
    return 0;
}

