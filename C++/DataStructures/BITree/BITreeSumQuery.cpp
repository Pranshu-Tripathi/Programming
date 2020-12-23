#include<bits/stdc++.h>
using namespace std;
#define MAXN 2000005

int a[MAXN];
int bit[MAXN] = {0};

void update(int i, int val, int n)
{
    for(; i <= n ; i += i & -i)
    {
        bit[i] += val;
    }
}

long long query(int n, int i)
{
    long long sum = 0;

    for(; i > 0 ; i -= i & -i)
    {
        sum += bit[i];
    }

    return sum;
}


void _run()
{
    int n;
    cin >> n;

    for(int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
        update(i,a[i],n);
    }

    int m;
    cin >> m;
    while(m--)
    {
        int x,val;
        int l,r;
        // update a[x] to val
        update(x,val - a[x],n);

        // range query l to r

        cout << query(r,n) - query(l-1,n) << endl;
    }

}

int main()
{
    int test = 1;
    while(test--)
        _run();
    return 0;
}