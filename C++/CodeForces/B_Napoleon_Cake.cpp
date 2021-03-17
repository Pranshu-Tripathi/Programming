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
    cin>>n;
    int a[n];
    for(int i = 0 ; i < n ; i++)
        cin>>a[i];
    int last_index=n;
    bool ans[n]={0};
    for(int i=n-1;i>=0;i--)
    {
        int ind = i-a[i]+1;
        last_index = min(last_index, ind);
        // cout<<lest<<endl;
        if(i >= last_index)
        {
            ans[i]=1;
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout << endl;
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
