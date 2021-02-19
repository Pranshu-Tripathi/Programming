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
    {
        cin >> a[i];
    }
    double ratio;
    int cnt = 0;
    for(int i = 0 ; i < n - 1 ; i++)
    {
        if(max(a[i],a[i+1]) > 2 * min(a[i],a[i+1]))
        {
            int temp = min(a[i],a[i+1]);
            while(temp < max(a[i],a[i+1]))
            {
                temp *= 2;
                cnt++;
            }
            cnt--;
        }
    }

    cout << cnt << endl;

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
