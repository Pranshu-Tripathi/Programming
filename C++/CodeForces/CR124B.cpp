#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

const string inifi = "Infinity";

void _run()
{
    int n,m;
    cin >> n >> m;
    int cofn[n+1],cofm[m+1];
    for(int i = 0 ; i <= n ; i ++)
        cin >> cofn[i];
    for(int i = 0 ; i <= m ; i++)
        cin >> cofm[i];
    
    if(n > m)
    {
        if(cofn[0] * cofm[0] > 0)
            cout << inifi << endl;
        else
            cout << '-' << inifi << endl;
    }

    else if(n == m)
    {
        int gcd = __gcd(abs(cofn[0]),abs(cofm[0]));
        int num = cofn[0]/gcd;
        int den = cofm[0]/gcd;
       // cout << cofm[0] << ' ' << cofn[0] <<' ' <<  gcd << endl;
        if(cofn[0] * cofm[0] < 0)
            cout << '-' << abs(num) << '/' << abs(den) << endl;
        else
            cout << abs(num) << '/' << abs(den) << endl;
    }

    else
    {
        cout << 0 << '/' << 1 << endl; 
    }
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
