#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

int sumDigits(ll x)
{
    ll sum = 0;
    while(x)
    {
        sum += x%10;
        x/=10;
    }
    return sum;
}

bool isPerfectSquare(long double x)
{
    if (x >= 0) {
 
        long double sr = sqrt(x);
         
        return (sr * sr == x);
    }
    return false;
}

void _run()
{
    ll n;
    cin >> n;
    ll ac = 4 * n;
    vector<int> psums;
    for(ll i = 0 ; i <= 90; i++)
    {
        if(isPerfectSquare(ac+i*i))
        {
            psums.push_back(i);
        }
    }

    if(psums.size() == 0)
    {
        cout << -1 << endl;
        return;
    }

    // for(int x : psums)
    //     cout << x << ' ';
    // cout << endl;
    vector<int> possible;
    for(int i = 0;i < psums.size() ; i++)
    {
        ll po = pow(psums[i],2);
        ll x =  (-psums[i] + (ll)sqrt(ac+po))/2;
        int digs = sumDigits(x);
        // cout << x << ' ' << digs << endl;
        if(x * (x + digs)  == n)
            possible.push_back(x);
    }

    if(possible.size() == 0)
    {
        cout << -1 << endl;
        return;
    }

    // for(int x : possible)
    //     cout << x << ' ';
    // cout << endl;

    sort(possible.begin(),possible.end());
    for(int i = 0 ; i < possible.size() ; i++)
    {
        if(possible[i] > 0)
        {
            cout << possible[i] << endl;
            break;
        }
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
