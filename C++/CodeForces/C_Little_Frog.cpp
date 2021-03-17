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
    vector<int> p(n+1);
    p[1] = 1;
    p[2] = n;
    for(int i = 3 ; i <= n ; i+=2)
        p[i] = p[i-2] + 1;
    for(int i = 4 ; i <= n ; i+= 2)
        p[i] = p[i-2] - 1;
    for(int i = 1 ; i <= n ; i++)
        cout << p[i] << ' ';
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
