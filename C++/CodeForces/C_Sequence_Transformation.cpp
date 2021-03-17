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
    int a[n];
    int fre[n+1];
    memset(fre,0,sizeof(fre));
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    for(int i = 0 ; i < n ; i++)
    {
        int j = i + 1;
        fre[a[i]]++;
        for( ; j < n ; j++)
        {
            if(a[j] != a[j-1])
                break;
        }
        i = j-1;
    }
    int best = n+1;
    for(int i = 0 ; i < n ; i++)
    {
        int fx = fre[a[i]];
        fx++;
        if(a[i] == a[0])
            fx--;
        if(a[i] == a[n-1])
            fx--;
        best = min(fx,best);
    }
    cout << best << endl;
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
