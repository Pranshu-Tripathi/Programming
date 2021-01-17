#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define fast    ios::sync_with_stdio(false); \
                        cin.tie(NULL)              

void _run()
{
    int n,k;
    cin >> n >> k;
    if(k== n)
    {
        cout << -1 << endl;
        return ;
    }

    int a[n+1];
    for(int i = 1 ; i <= n ; i++)
        a[i]=i;
    
    int swaps = n - 1 - k;
    for(int i = 2 ; i <= n ; i+=2)
    {
        if(swaps <= 1)
            break;
        swap(a[i],a[i+1]);
        swaps -= 2;
    }

    if(swaps == 1)
        swap(a[1],a[n]);
    
    for(int i = 1 ; i <= n ; i++)
        cout << a[i] << " ";
    cout << endl;

    // int gcd = 0;
    // for(int i = 1 ; i <= n ; i ++)
    // {
    //     if(__gcd(i,a[i]) > 1)
    //         cout << a[i] << ":" << i << endl,gcd++;
    // }
    // cout << gcd << endl;
}

int main()
{
    fast;
    int test = 1;
    while(test--)
        _run();
    return 0;
}