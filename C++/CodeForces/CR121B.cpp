#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
    }
    vector<int> daycon(n);
    daycon[0] = 100000;
    for(int i = 1 ; i < n ; i++)
    {
        daycon[i] = max(a[i],a[i-1]);
    }

    cout << min(a[n-1],min(a[0],*min_element(daycon.begin(),daycon.end())));
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
