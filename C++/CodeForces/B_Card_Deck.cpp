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
    int n;
    cin >> n;
    int p[n];
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        s.insert(i + 1);
    }
    int lindx = n - 1;
    while (s.size() > 0)
    {
        auto it = s.rbegin();
        int val = *it;
        int targ;
        for (int i = lindx; i >= 0; i--)
        {
            if (p[i] != val)
                s.erase(p[i]);
            if (p[i] == val)
            {
                targ = i;
                s.erase(p[i]);
                break;
            }
        }
        for (int i = targ; i <= lindx; i++)
        {
            printf("%d ", p[i]);
        }
        lindx = targ - 1;
    }
    printf("\n");

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
