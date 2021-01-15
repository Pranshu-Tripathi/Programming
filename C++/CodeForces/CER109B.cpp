#include<bits/stdc++.h>
using namespace std;
#define ll long long

void _run()
{
    string s,t;
    cin >> s >> t;
    if(s == t)
    {
        cout << s << endl;
        return;
    }
    string a = s,b = t;

    while(true)
    {
        if(s.length() == t.length())
            break;
        else if(s.length() < t.length())
            s += a;
        else if(s.length() > t.length())
            t += b;
    }

    if(s == t)
        cout << s << endl;
    else
        cout << -1 << endl;

    return;
}

int main()
{
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}