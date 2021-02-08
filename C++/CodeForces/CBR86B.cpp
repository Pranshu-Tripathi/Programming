#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

bool notAll(vector<int>& isue)
{
    for(int &x : isue)
        if(x != __INT_MAX__)
            return false;
    
    return true;
}

void _run()
{
    int n,m;
    cin >> n >> m;
    vector<string> names(n);
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> names[i];
    }

    map<string,vector<string>> graph;
    for(int i = 0 ; i < m ; i++)
    {
        string s,t;
        cin >> s >> t;
        graph[s].push_back(t);
        graph[t].push_back(s);
    }

    vector<int> isue(n);
    for(int i= 0 ; i < n ; i++)
    {
        isue[i] = graph[names[i]].size();
    }

    vector<string> ans;
    while(!notAll(isue))
    {

        for(int i = 0 ; i < n ; i ++)
        {
            cout << names[i] << "         " << isue[i] <<endl;
        }
        int min = __INT_MAX__;
        int idx = -1;
        for(int i = 0 ; i < n ; i ++)
        {
            if(min > isue[i])
                min = isue[i], idx = i;
        }

        ans.push_back(names[idx]);
        isue[idx] = __INT_MAX__;

        for(string &s : graph[names[idx]])
        {
            for(int i =  0; i < n ; i ++)
            {
                if(names[i] == s)
                {
                    isue[i] = __INT_MAX__;
                    break;
                }
            }
        }
    }

    cout << ans.size() << endl;
    sort(ans.begin(),ans.end());
    for(string &k : ans)
        cout << k << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
