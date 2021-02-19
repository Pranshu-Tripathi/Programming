#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

bool minusPresent(vector<int>& s)
{
    ll num = 0;
    vector<int> finalDigs;
    for(int i = 0 ; i< s.size() ; i++)
    {
        if(i != s.size() - 2)
            finalDigs.push_back(s[i]);
    }
    for(int i = finalDigs.size() - 1 ; i >= 0 ;i--)
    {
        num += pow(10,finalDigs.size() - 1 - i) * finalDigs[i];
    }
    return num > 0;
}

void _run()
{
    ll n;
    cin >> n;
    if(n >= 0)
    {
        cout << n << endl;
        return;
    }

    vector<int> s;
    ll temp = - n;
    int last = temp%10;
    
    while(temp)
    {
        s.push_back((temp%10 ));
        temp/=10;
    }

    reverse(s.begin(),s.end());

    int secLast = (-n)%100;
    secLast -= last;
    secLast /=10;

    if(secLast <= last)
    {
        cout << '-';
        for(int i = 0 ; i < s.size() - 1 ; ++i)
        {
            cout << s[i];
        }
    }
    else
    {
        if(minusPresent(s))
            cout << '-';
        for(int i = 0 ; i < s.size() ; ++i)
        {
            if(i != s.size() - 2)
                cout << s[i];
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
