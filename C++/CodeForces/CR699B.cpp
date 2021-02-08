#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    ll n , k;
    cin >> n >> k;
    ll arr[n];
    for(int i = 0 ; i< n ; i ++)
    {
        cin >> arr[i];
    }
    int pos;
    for(int j = 0 ; j < k ; j++)
    {   
        int i;
        for(i = 0 ; i < n-1 ; i++)
        {
            if(arr[i] < arr[i+1])
            {
                arr[i]++;
                break;
            }
        }

        if(i == n -1)
        {
            pos = i;
            break;
        }

        if(j == k -1)
        {
            pos = i;
        }
    }

    if(pos == n - 1)
        cout << -1 << endl;
    else
        cout << pos+1 << endl;
}

int main()
{
    fast;
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
