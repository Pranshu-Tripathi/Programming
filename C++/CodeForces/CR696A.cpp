#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n;
    cin>>n;
    string b;
    cin>>b;
    string ans = b;
    char pre = '0';
    ans[0] = '1';
    for(int i=1;i<n;i++)
    {
        if(b[i-1] == '1' && ans[i-1] == '1')
        {
            if(b[i] == '1')
            {
                ans[i] = '0';
            }
            else
            {
                ans[i] = '1';
            }
        }
        else if(b[i-1] == '0' && ans[i-1] == '0')
        {
            ans[i] = '1';
        }
        else 
        {
            if(b[i] == '1')
            {
                ans[i] = '1';
            }
            else
            {
                ans[i] = '0';
            }
        }
    }
    cout<<ans<<endl;
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
