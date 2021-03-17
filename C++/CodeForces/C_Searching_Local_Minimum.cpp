#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000009

int query(int x , int n)
{
    int ans = -1;
    if(x <= n && x >= 1)
    {
        cout << '?' << ' ' << x << endl;
        cout.flush();
        cin >> ans;
    }
    return ans;
}

void answer(int x)
{
    cout << '!' << ' ' <<x << endl;
    cout.flush();
}

void _run()
{    
    int n;
    cin >> n;
    int l = 1;
    int r = n;
    while( l < r )
    {
        int mid = (l+r)/2;
        int x = query(mid,n);
        int q = query(mid+1,n);
        if(x < q) 
            r = mid ;
        else
            l = mid + 1;
    }
    answer(l);
    
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
