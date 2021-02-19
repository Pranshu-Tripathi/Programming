#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

void _run()
{
    int n;
    cin >> n;
    ll a[n];
    ll sum = 0;
    for(int i = 0 ; i < n ; i++)
        cin >> a[i], sum+=a[i]; 
    //cout <<"Sum :" << sum << endl;      
    ll l = 0,r = 1000000000;
    ll mid;
    ll mx = *max_element(a,a+n);
    while(l < r)
    {
        mid = (l+r)/2;
        if(l == mid)
            break;
        //cout << mid << ' ' <<  l << ' ' << r << endl;
        ll matches = (n-1) *mid;
        //cout << matches << endl;
        if(matches > sum && mid >= mx)
            r = mid - 1;
        else if(matches < sum || mid < mx)
            l = mid;
        if(matches == sum && mid >= mx)
            break;
        
    }
    mid = max(mx,mid);
    ll ans = ceil(sum/(double)(n-1));
    if(mid < ans)
        mid = ans;
    cout << mid ;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
