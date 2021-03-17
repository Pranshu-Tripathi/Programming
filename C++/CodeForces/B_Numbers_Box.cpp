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
    int n,m;
    cin >> n >> m;
    int a[n][m];
    int mi = 0;
    int mix = 1000;
    int sum = 0;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
        {
            cin >> a[i][j];
            if(a[i][j] < 0)
                mi++;
            mix = min(abs(a[i][j]),mix);
            sum += abs(a[i][j]);
        }
    
    if(mi % 2 == 0)
        cout <<sum << endl;
    else
        cout << sum - 2 * mix << endl;
    

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
