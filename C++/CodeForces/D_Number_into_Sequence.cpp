#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000009

void _run()
{    
    ll n,tem;
    cin >> n;
    tem = n;
    vector<ll> facts;
    for(ll i = 2 ; i * i <= n ; i++)
    {
        if(n % i == 0)
        {
            while(n % i == 0)
            {
                facts.push_back(i);
                n /= i;
            }
        }
    }
    if(n != 1)
        facts.push_back(n);
    
    // for(int i = 0 ; i < facts.size() ; i++)
    //     cout << facts[i] << ' ';
    // cout << endl;
    
    int num = -1;
    int fre = 0;
    for(int i = 0 ; i < facts.size() ; i++)
    {
        int j;
        for(j = i + 1 ; j < facts.size() ; j++)
        {
            if(facts[j] != facts[j-1])
                break;
        }
        int d = j - i;
        if(fre < d)
        {
            fre = d;
            num = facts[i];
        }
        i = j - 1;
    }
    if(fre == 1)
    {
        cout << 1 << endl <<  tem << endl;
    }
    else
    {
        int size = fre;
        cout << size << endl;
        for(int i = 0 ; i < fre-1 ; i++)
            cout << num << ' ';
        ll x = pow(num,fre-1);
        cout << tem/x << endl;
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
