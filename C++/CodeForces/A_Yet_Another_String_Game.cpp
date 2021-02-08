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
        cin>>s;
        bool flag = true;
        for(int i=0;i<s.size();i++)
        {
            if(flag)
            {
                if(s[i]=='a')s[i]='b';
                else s[i]='a';
                flag = !flag;
            }
            else
            {
            if(s[i]=='z')s[i]='y';
            else s[i]='z';
            flag = !flag;
            }
        }
    cout<<s<<endl;
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
