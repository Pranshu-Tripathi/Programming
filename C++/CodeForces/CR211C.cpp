#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    string s;
    cin >> s;
    int n = s.length();
    string ans = "";
    string an = "";

    for(int i = 0 ; i < n ; i ++)
    {
        if(i != n- 1 && s[i]==s[i+1])
        {
            int cou = 1;
            for(int j = i+1 ; j < n ; j ++)
            {
                if(s[j] == s[j-1])
                    cou++;
                else
                    break;
            }
            ans+=s[i];
            ans+=s[i+1];
            i += cou-1;
        }
        else
            ans +=s[i];
    }

    int m = ans.length();
    for(int i = 0 ; i < m ; i ++)
    {
        if(i <= m - 4 && ans[i] == ans[i+1] && ans[i+2] == ans[i+3] && ans[i] != ans[i+2])
        {
            an += ans[i];
            an += ans[i+1];
            an += ans[i+2];
            i += 3;
        }
        else
            an += ans[i];
    }
    cout << an << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
