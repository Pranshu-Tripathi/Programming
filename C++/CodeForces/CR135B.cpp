#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

void digits(ll p,vector<int>& dig)
{
    while(p)
    {
        dig.push_back(p%10);
        p/=10;
    }
    reverse(dig.begin(),dig.end());
}

void _run()
{
    ll p,d;
    cin >> p >> d;
    vector<int> digitP;
    digits(p,digitP);
    int count = digitP.size();
    for(int i = count - 1 ; i  > 0 ; --i)
    {
        // for(int i = 0 ; i < digitP.size() ; i++)
        // {      
        // cout << digitP[i];
        // }
        // cout << endl;
        int dig = digitP[i];
        if(dig == 9)
        {
            continue;
        }

        ll sub = 10 + dig - 9;
        ll po = pow(10,count - 1 - i);
        if(d - (sub * po) < 0)
            break;
        d -= (sub*po);
        digitP[i] = 9;
        digitP [i-1]--;
    }
    int zer= 0;
    for(zer = 0 ; zer < digitP.size() ; zer++)
    {
        if(digitP[zer] != 0)
            break;
    }
    for(int i = zer ; i < digitP.size() ; i++)
    {
        cout << digitP[i];
    }
    cout << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
