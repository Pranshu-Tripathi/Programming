#include<bits/stdc++.h>
using namespace std;
# define ll long long

const string first = "first";
const string second = "second";

void _run()
{
    int n;
    cin >> n;
    ll seq[n];
    vector<ll> fir,sec;
    ll F_sum = 0;
    ll S_sum = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> seq[i];
        if(seq[i] > 0)
            F_sum += seq[i],fir.push_back(seq[i]);
        else
            S_sum += abs(seq[i]),sec.push_back(abs(seq[i]));
    }

    if(F_sum > S_sum)
    {
        cout << first << endl;
        return;
    }
    else if(F_sum < S_sum)
    {
        cout << second << endl;
        return;
    }

    bool flag = false;

    int x = min(fir.size(),sec.size());

    for(int i = 0 ; i < x ; i++)
    {
        if(fir[i] > sec[i])
        {
            cout << first << endl;
            flag = true;
            break;
        }
        else if(fir[i] < sec[i])
        {
            cout << second << endl;
            flag = true;
            break;
        }
    }

    if(!flag)
    {
        int k = seq[n-1];
        if(k > 0)
            cout << first << endl;
        else
            cout << second << endl;
    }
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