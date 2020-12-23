#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005

int bit[MAXN];
int n;

void update(int i, int val)
{
    for(; i <= n ; i += (i&-i))
    {
        bit[i] += val;
    }
}

int query(int i)
{
    int sum = 0;

    for(; i > 0 ; i -= (i&-i))
    {
        sum += bit[i];
    }

    return sum;
}

int finding(int x)
{
    int ans = n;
    int l = 1,r = n;
    while(l <= r)
    {
        int md = (l + r) / 2;
        if(query(md) >= x)
        {
            r = md - 1;
            ans = md;
        }
        else
        {
            l = md+ 1;
        }
    }
    return ans;
}



void _run()
{
    int q;
    cin >> n >> q;

    int a;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a;
        update(a,1);
    }

    int k;
    while(q--)
    {
        cin >> k;
        if(k > 0)
            update(k,1);
        else
            update(finding(-k) , -1);
    }

    if(query(n) == 0)
        cout << '0' << endl;
    else 
        cout << finding(1) << endl;
    
    return ;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);

    _run();

    return 0;
}