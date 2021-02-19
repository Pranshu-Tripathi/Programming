#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double

void _run()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    
    sort(a,a+n);

    if(a[0] == a[n-1])
    {
        cout << 0 << endl;
        return;
    }

    int co = 0;
    for(int i = 0 ; i< n ;i++)
    {
        if(a[0] != a[i])
            break;
        co++;
    }

    cout << n - co << endl;

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
