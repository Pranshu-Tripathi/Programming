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
    cin >> s;
    int a[s.length()] = {0};
    vector<string> words;

    if(s.length() < 3)
    {
        cout << s ;
        return;
    }

    for(int i = 0 ; i < s.length() - 2 ; i++)
    {
        if(s[i] == 'W' && s[i+1] =='U' && s[i+2] == 'B')
        {
            a[i] = a[i+1] = a[i+2] = 1;
        }
    }

    // for(int i = 0 ; i < s.length() ; i++)
    // {
    //     cout << a[i];
    // }
    // cout << endl;

    for(int i = 0 ; i < s.length() ; i++)
    {
        if(a[i] == 0)
        {
            string t = "";
            int j;
            for(j = i ; a[j] != 1 && j < s.length(); j++)
            {
                t += s[j];
            }
            words.push_back(t);
            i = j;
        }
    }

    for( auto x : words)
    {
        cout << x << ' ' ;
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
