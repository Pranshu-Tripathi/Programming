#include<bits/stdc++.h>
using namespace std;

vector<long long> bit(1000001,0);
long long n;

void update(long long i, long long val)
{
    for(; i <= n ; i += (i&-i))
    {
        bit[i] += val;
    }
}

long long query(long long i)
{
    long long sum = 0;
    for(; i > 0 ; i -= (i&-i))
    {
        sum += bit[i];
    }
    return sum;
}

void _run()
{
    long long m,c;
    cin >> n >> m >> c;

    while(m--)
    {
        char ch;
        long long u,v;
        long long k,p;
        cin >> ch;
        if(ch == 'Q')
        {
            cin >> p;
            cout << (query(p) + c) << "\n";
        }
        else
        {
            cin >> u >> v >> k;
            update(u,k);
            update(v+1,-k);
        }
    }    

    return;
}

int main()
{
    ios::sync_with_stdio(false),
    cin.tie(NULL);

    _run();
    return 0;
}