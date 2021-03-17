#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define ld long double
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define mod 1000000009

vector<ll> facts;

int _factorization(ull n)
{
    for(ull i = 2; i * i <= n ; i++)
    {
        if(n%i == 0)
        {
            while(n % i == 0)
            {
                n/=i;
                facts.push_back(i);
            }
        }
    }
    if(n != 1)
    {
        facts.push_back(n);
    }
    // for(ll x : facts)
    //     cout << x << ' ';
    return facts.size();
}

void _run()
{
    ull n;
    cin >> n;
    int size = _factorization(n);
    if(facts.size() <= 1)
        cout << 1 << endl << 0;
    else if(facts.size() == 2)
        cout << 2 << endl;
    else
        cout << 1 << endl << facts[0] * facts[1] << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
