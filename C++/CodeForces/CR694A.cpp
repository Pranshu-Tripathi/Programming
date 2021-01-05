#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    ll n,x;
    cin >> n >> x;
    ll arr[n];
    ll s1 = 0, s2 = 0;

    for(int i =0 ; i < n ; i++)
    {
        cin >> arr[i];
        s1 += arr[i] / x;
        if(arr[i] % x)
        {
            s1 ++;
        } 
        s2 += arr[i];
    }
    ll ans=0;
    if(s2%x)
    {
        ans++;
    }
    s2 = s2/x;
    s2 += ans;
    cout<<s2<<" "<<s1<<endl;
    return;
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
