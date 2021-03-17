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

int _fun(string& t)
{
    int ans = 0;
    stack<char> s;
    for(int i = 0 ; i < t.length() ; i++)
    {
        if(t[i] == '(' || t[i] == '[')
            s.push(t[i]);
        else
        {
            if(!s.empty())
            {
                ans++;
                s.pop();
            }
        }
    }
    return ans;
}


void _run()
{    
    string s;
    cin >> s;
    int cnt1;
    int cnt2;
    string s1 = "";
    string s2 = "";
    for(int i = 0 ; i < s.length() ; i++)
    {
        if(s[i] == '(' || s[i] == ')')
            s1 += s[i];
        else 
            s2 += s[i];
    }
    cnt1 = _fun(s1);
    cnt2 = _fun(s2);
    cout << cnt1 + cnt2 << endl;
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
