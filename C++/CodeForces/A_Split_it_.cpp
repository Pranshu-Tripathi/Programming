/*
PR7
*/
#include<bits/stdc++.h>
using namespace std;

#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define mod 1000000009
#define debug(a...) cout<<#a<<": ";for(auto it:a)cout<<it<<" ";cout<<endleft;


void _run()
{    
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int left=0,r=n-1;
    while(left < r)
    {
        if(s[left] != s[r])
        {
            break;
        }
        left++;
        r--;
    }
    if(left==k)
    {
        if(left > r)
        {
            cn;
        }
        else
        {
            cy;
        }
        return;
    }
    if(left > k)
    {
        cy;
    }
    else
    {
        cn;
    }
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
