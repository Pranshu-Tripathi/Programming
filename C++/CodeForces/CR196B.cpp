#include<bits/stdc++.h>
using namespace std;

#define ll long long


void _run()
{
    ll a,b,c,d,num,den,gcd;
    cin >> a >> b >> c >> d;
    if(c * b <= d * a)
    {
        num = (a*d) - (b*c);
        den = (a*d);
        gcd = __gcd(num,den);
        
    }
    else
    {
        num =  (b*c) -(a*d);
        den = (b*c);
        gcd =  __gcd(num,den);
    }
    num /= gcd;
    den /= gcd;
    cout << num << "/" << den << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    while(test--)
        _run();
    return 0;
}