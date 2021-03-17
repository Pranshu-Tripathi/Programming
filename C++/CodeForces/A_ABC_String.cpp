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

bool regular(string & t)
{
    stack<char> s;
    for(int i = 0 ; i < t.length() ; i++)
    {
        if(t[i] == '(')
            s.push('(');
        else
        {
            if(s.empty())
                return false;
            s.pop();
        }
            
    }

    return s.empty();
}

void _run()
{    
    string s;
    cin >> s;
    int n = s.length();
    char opner = s[0];
    char closer = s[n-1];
    char left ='#';
    if(opner == closer)
    {
        cn;
        return;
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] != opner && s[i] != closer)
        {
            left = s[i];
            break;
        }
    }
    
    string t1 = "";
    string t2 = "";

    // considering open
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == opner)
            t1 += '(',t2+= '(';
        else if(s[i] == closer)
            t1 += ')',t2 += ')';
        else
            t1 += '(',t2 += ')';
    }

    // cout << t1 << endl;
    // cout << t2 << endl;

    bool reg1 = regular(t1);
    bool reg2 = regular(t2);
    // cout << reg1 << ' ' << reg2 << endl;
    if(reg1 || reg2)
        cy;
    else
        cn;
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
