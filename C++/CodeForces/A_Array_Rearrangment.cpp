#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "Yes" << endl
#define cn cout << "No" << endl
#define ld long double
#define mod 1000000009

void _run()
{    
    int n,x;
    cin >> n >> x;
    int a[n],b[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    for(int i = 0 ; i < n ; i++)
        cin >> b[i];
    sort(a,a+n);
    sort(b,b+n,greater<int>());
    for(int i = 0 ; i < n ; i++)
        if(a[i] + b[i] > x)
        {
            cn;
            return;
        }
    cy;
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
