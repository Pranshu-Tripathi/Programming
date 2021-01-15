#include<bits/stdc++.h>
using namespace std;

#define ll long long

void _run()
{
    string s;
    cin >> s;
    int four = 0;
    int seven = 0;
    for(int i = 0 ; i < s.length(); i++)
    {
        if(s[i] == '4')
            four++;
        else if(s[i] == '7')
            seven++;
    }

    if(four == 0 && seven == 0)
    {
        cout << -1 << endl;
        return;
    }

    if(four >= seven)
        cout << '4' << endl;
    else
        cout << '7' << endl;
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