/*
PR7
*/
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
#define debug(a...) cout<<#a<<": ";for(auto it:a)cout<<it<<" ";cout<<endl;


void _run()
{    
    int n;
    cin >> n;
    int r[n];
    for(int i = 0 ; i < n ; i++)
        cin >> r[i];
    int m;
    cin >> m;
    int b[m];
    for(int i = 0 ; i  < m ; i++)
        cin >> b[i];
    int pre[n];
    int preb[m];
    pre[0] = r[0];
    preb[0] = b[0];

    for(int i = 1 ; i<n ; i++)
        pre[i] = pre[i-1] + r[i];
    for(int i = 1 ;i <m ; i++)
        preb[i] = preb[i-1] + b[i];
    
    int best = max(preb[0],max(pre[0] , pre[0] + preb[0]));
    best = max(0,best);
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++ )
            best = max(best,max(pre[i],max(preb[j],preb[j] + pre[i])));
    
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
