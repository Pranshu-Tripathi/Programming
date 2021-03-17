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

void _run()
{    
    int n,k;
    cin >> n >> k;
    int a[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    sort(a,a+n);
    int pos = -1;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i]+k > 5)
            break;
        else
            pos = i; 
    }
    int peop = pos+1;
    cout <<  peop/3;
}

int main()
{
    fast;
    int test = 1;
    while(test--)
        _run();
    return 0;
}
