#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    ll n,k;
    cin >>n >> k;
    if(n > k && k != 1)
        cout << (n%k == 0 ? 1 : 2) << endl;
    else
        cout << (k%n == 0? k/n : k/n+1) << endl;
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
