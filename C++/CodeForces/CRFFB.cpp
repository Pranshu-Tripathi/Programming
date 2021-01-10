#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> alp(26);

void _run()
{
    string s;
    cin >> s;
    ll k;
    cin >> k;
    int I = 0;
    ll mx = -1;
    ll sum = 0;
    for(int i = 0 ; i < 26 ; i++)
    {
        cin >> alp[i];
        if(mx < alp[i])
        {
            mx = alp[i];
            I = i;
        }
    }
    
    for(int i = 0;i < s.length(); i++)
    {
        sum+= (i+1)*alp[(int)s[i] -97];
    }
    
    int len = s.length();
    for(int i = len ; i < len + k ; i++)
    {
        sum += (i+1) * mx;
    }

    cout << sum << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    while(test--)
        _run();
    return 0;
}
