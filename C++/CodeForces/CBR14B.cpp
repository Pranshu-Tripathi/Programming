#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n,x;
    int a,b,t;
    cin >> n >> x >> a >> b;
    if(a > b)   t = a,a = b, b = t;
    int mina = a,maxb = b;
    for(int i = 0 ; i < n -1 ; i++)
    {
        cin >> a >> b;
        if(a > b)   t = a,a = b, b = t;
        mina = max(mina,a);
        maxb = min(maxb,b);
    }

    if(mina > maxb)
    {
        cout << -1 << endl;
    }

    else if(x > maxb)
        cout << x - maxb << endl;
    else if(x < mina)
        cout << mina - x << endl;
    else
        cout << 0 << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
