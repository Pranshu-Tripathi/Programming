#include<bits/stdc++.h>
using namespace std;
#define ll long long
void run_test()
{
    int n,k;
    cin >> n >> k;
    ll arr[n*k+1];
    for(int i = 0 ; i < n*k ; i++)
        cin >> arr[i];
    
    int steps = n*(k-1) - 1 + n/2;

    if(n % 2 != 0)  
        steps++;
    
    ll ans = 0;

    for(int i = 0 ; i < k ;i ++)
        ans += arr[steps] , steps -= (n/2+1);
    cout << ans << endl;
}

int main()
{
    int test;
    cin >> test;
    while(test--)
        run_test();
    return 0;
}