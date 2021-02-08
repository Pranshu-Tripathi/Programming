#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    ll h,w;
    cin >> w >> h;
    ll ans = 0;
    if(w < 2 || h < 2)
    {
        cout << ans << endl;
        return;
    }
    ll ans1 = 0 ,ans2=0;
    for(int i = 2 ; i <= w ; i+=2)
        ans1+= (w-i+1);
    for(int i = 2 ; i <=h ; i +=2)
        ans2+= (h-i+1);
    ans = ans1 * ans2;
    cout << ans << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
