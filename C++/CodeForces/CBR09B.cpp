#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    ll n;
    long double vb,vs;cin>>n>>vb>>vs;
    long double a[n];
    for(int i = 0 ; i < n ; i++) 
        cin>>a[i];
    long double x,y;cin>>x>>y;
    ll ans=1;
    long double dis=LDBL_MAX,ch=LDBL_MAX;
    for(int i = 1; i < n ; i++)
    {
        long double bus=0,stu=0;
        if(vb!=0)
            bus=a[i]/(vb);
        if(vs!=0)
            stu=sqrt((x-a[i])*(x-a[i]) + (y)*(y))/vs;
        long double dis2=bus+stu;
        //cout<<dis2<< " "<<dis<< " ";
        if(dis2 < dis)
        {
            dis=dis2;
            ch=sqrt((x-a[i])*(x-a[i]) + (y)*(y));
            ans=i+1;
        }
        else if(dis2-dis<1e-9 && sqrt((x-a[i])*(x-a[i]) + (y)*(y)) <ch )
        {
            dis=dis2;
            ch=sqrt((x-a[i])*(x-a[i]) + (y)*(y));
            ans=i+1;
        }
    }
 
    cout<<ans;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
