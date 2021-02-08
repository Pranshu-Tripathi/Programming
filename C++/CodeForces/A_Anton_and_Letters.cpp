#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

void _run()
{
    string s;
    getline(cin,s);
    set<char> unique;
    for(int i = 0 ; i < s.length() ;i++)
    {
        if(s[i] != '{' && s[i] != '}' && s[i] != ',' && s[i] != ' ')
            unique.insert(s[i]);
    }

    cout << unique.size();
    
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
