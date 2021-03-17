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
    int fre[201];
    map<int,vector<pair<int,int>>> x;
    memset(fre,0,sizeof(fre));
    int a[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    for(int i = 0 ; i < n ; i++)
        for(int j = i+1 ; j < n ; j++)
        {
            if(x.find(a[i]+a[j]) == x.end())
            {
                x[a[i]+a[j]].push_back({i,j});
                fre[a[i]+a[j]]++;
            }
            else
            {
                bool possi = true;
                for(auto p : x[a[i]+a[j]])
                    if(p.first == i || p.second == i || p.first == j || p.second == j)
                        possi = false;
                if(possi)
                    x[a[i]+a[j]].push_back({i,j}),fre[a[i]+a[j]]++;
            }
        }
    //debug(fre);
    int mx = 0;
    for(int i = 0 ; i < 201 ; i++)   
        mx = max(mx,fre[i]);
    cout << mx << endl;
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
