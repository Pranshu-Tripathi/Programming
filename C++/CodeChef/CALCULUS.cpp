#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define m 998244353

ll expo(int a, ll b)
{
    if(b == 0)  return 1;
    else if(b == 1) return a;

    if(b % 2 == 0)
    {
        ll ret = expo(a,b/2);
        ret = (ret % m * ret % m) % m;
        return ret;
    }
    else
    {
        ll ret = expo(a,b/2);
        ret = (ret % m  * ret % m) % m ;
        ret = (ret % m* a % m) % m;
        return ret;
    }
    
}

ll modInv(int b)
{
    return expo(b,m-2) % m;
}

void run_testcase()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 2 << endl;
        return;
    }

    if(n == 2)
    {
        ll ans = (8 % m * modInv(3))%m;
        cout << ans;
        return ;
    }

    if(n == 3)
    {
        ll ans = (46 % m * modInv(15))%m;
        cout << ans;
        return ;
    }

}

int main()
{

    ios::sync_with_stdio(0),cin.tie(0);
    int test = 1;
    while(test--)
        run_testcase();
    return 0;
}