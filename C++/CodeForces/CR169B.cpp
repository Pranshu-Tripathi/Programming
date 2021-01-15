#include<bits/stdc++.h>
using namespace std;
#define ll long long

const string first = "First";
const string second = "Second";
int f[26];

void _run()
{
    string s;
    cin >> s;

    int n = s.length();
    for(int i = 0; i < n ; i++)
    {
        f[s[i] - 'a']++;
    }
    int charOdd = 0;
    for(int i = 0 ; i < 26 ;i++)
    {
        if(f[i] % 2 != 0)
            charOdd++;
    }

    if(charOdd <= 1) 
        cout << first << endl;
    else if(charOdd % 2 == 0)
        cout << second << endl;
    else 
        cout << first << endl;
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
