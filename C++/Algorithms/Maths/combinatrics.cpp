#include<bits/stdc++.h>
using namespace std;
#define ll long long

int ncr[1001][1001];
bool vis[1001][1001];

ll getNCR(int n, int r)
{
    if(vis[n][r])
    {
        return ncr[n][r];
    }
    else if(r == 0 || r == 1)
    {
        vis[n][r] = true;
        ncr[n][r] = n;
    }
    else if(n == 0)
    {
        vis[n][r] = true;
        ncr[n][r] = 0;
    }
    else 
    {
        vis[n][r] = true;
        ncr[n][r] = getNCR(n-1,r) + getNCR(n-1,r-1);
    }
    return ncr[n][r];
}


int main()
{
    ll ncd = getNCR(10,2);
    ncd = getNCR(10,1);
    cout << ncd << endl;
}