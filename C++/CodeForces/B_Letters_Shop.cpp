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

void _run()
{    
    int n;
    cin >> n;
    string t;
    cin >> t;
    int m;
    cin >> m;
    vector<int> graph[26];
    int fre[m][26];
    memset(fre,0,sizeof(fre));
    vector<string> s(m);
    for(int i = 0 ; i < m ; i++)
        cin >> s[i],sort(s[i].begin(),s[i].end());
    for(int i = 0 ; i < n ; i ++)
        graph[t[i] - 'a'].push_back(i);
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < s[i].length() ; j++)
            fre[i][s[i][j] - 'a']++;
    }

    for(int i = 0 ; i < m ; i++)
    {
        int bestIdx = 0;
        for(int j = 0 ; j < s[i].length() ; j++)
        {
            int f = fre[i][s[i][j] - 'a'];
            int idx = graph[s[i][j] - 'a'][f-1];
            bestIdx = max(idx,bestIdx);
            j += f-1;
        }
        cout << bestIdx+1 << endl;
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
