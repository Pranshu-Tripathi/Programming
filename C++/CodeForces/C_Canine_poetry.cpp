/*
PR7
*/
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
#define debug(a...) cout<<#a<<": ";for(auto it:a)cout<<it<<" ";cout<<endl;

bool isPal(string s, int l, int r)
{
    return s[l] == s[r];
}
    

void _run()
{    
    string s;
    cin >> s;
    bool used[s.length()];
    memset(used,false,sizeof(used));
    int ans = 0;
    for(int i = 1 ; i < s.length() ; i++)
    {
        if(isPal(s,i-1,i) && !used[i] && !used[i-1])
            used[i] = true,ans++;
        if(i > 1)
        {
            if(isPal(s,i-2,i) && !used[i]  && !used[i-2])
                used[i] = true,ans++;
        }
    }


    cout << ans << endl;
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
