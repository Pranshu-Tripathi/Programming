#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double


void heightTree(int l, int r, int a[], map<int,int>& ans, int f)
{
    if(l > r)
    {
        return;
    }
    int mx=a[l], ind=l;
    for(int i=l+1;i<=r;i++)
    {
        if(mx < a[i])
        {
            mx = a[i];
            ind = i;
        }
    }
    ans[a[ind]] = f;
    f++;
    heightTree(l, ind-1, a, ans, f);
    heightTree(ind+1, r, a, ans, f);
}

void _run()
{
     int n;
    cin>>n;
    int a[n];
    for(int i = 0 ; i < n ; i++)
    {
        cin>>a[i];
    }
    map<int,int> ans;
    heightTree(0,n-1,a,ans, 0);
    for(int i = 0; i  < n ; i++)
    {
        cout<<ans[a[i]]<<" ";
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
