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
    int pts[n];
    for(int i =0 ; i < n ; i++)
        cin >> pts[i];
    set<int> a;
    for(int i = 0 ; i < n ; i++)
        for(int j = i+1 ; j < n ; j++)
            a.insert(abs(pts[i]-pts[j]));
    cout << a.size() << endl;
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
