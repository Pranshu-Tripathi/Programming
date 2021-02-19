#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(false),\
                    cin.tie(0),\
                    cout.tie(0)
#define cn cout << "NO" << endl
#define cy cout << "YES" << endl

const string noSol = "No solution";

void _run()
{
    string s;
    cin >> s;
    int co = 0;
    bool conse = false;
    int n = s.length();
    for(int i = 0 ; i < n ; i++)
    {
        if(s[i] == '@')
        {
            co++;
            for(int j = i+1 ; j < n && j < i+3 ; j++)
            {
                if(s[j] == '@')
                {
                    conse = true;
                    break;
                }    
            }
        }
    }

    if(n < 3*co || s[0] == '@' || s[n-1] == '@' || conse || co == 0)
    { 
        cout << noSol << endl;
        return;
    }
    vector<string> ans;
    for(int i = 0 ; i < n ; i++)
    {
        string t = "";
        int j;
        for(j = i ; j < n &&  s[j] != '@' ; j++)
        {
            t += s[j];
        }
        t += s[j];
        for(j = j + 1 ; j < n  && s[j+1] != '@' ; j++)
        {
            t += s[j];
        }
        i = j-1;
        ans.push_back(t);
    }
    for(int i = 0 ; i < ans.size() - 1; i++)
        cout << ans[i] <<',';
    cout << ans[ans.size() - 1] ;
}

int main()
{
    fast;
    int test = 1;
    while(test--)
        _run();
    return 0;
}