#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n,t;
    cin >> n >> t;
    string s;
    cin >> s;
    bool vis[n] = {false};
    while(t--)
    {
        memset(vis,false,sizeof(vis));
        for(int i = 0; i < n - 1 ; i++)
        {
            if(s[i] == 'B' && s[i+1] == 'G' && !vis[i] && !vis[i+1])
                swap(s[i],s[i+1]),vis[i] = vis[i+1] = true;
        }
    }
    cout << s << endl;
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
