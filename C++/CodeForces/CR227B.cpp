#include<bits/stdc++.h>
using namespace std;
#define ll long long
int freq[1000001];

void _run()
{
    int n,m;
    cin >> n >> m;
    int required[n];
    int problems[m];

    for(int i = 0 ; i < n ; i++)
        cin >> required[i];
    
    for(int i = 0 ; i < m ; i++)
        cin >> problems[i], freq[problems[i]]++;

    vector<int> issues;

    for(int i = 0 ; i < n ; i++)
    {
        if(freq[required[i]] == 0)
            issues.push_back(required[i]);
        else
        {
                freq[required[i]]--;
                for(int  j = 0 ; j < m ; j++)
                {
                    if(required[i] == problems[j])
                    {
                        problems[j] = -1;
                        break;
                    }    
                }
        }
    }

    // for(auto k : problems)
    //     cout << k << " ";

    // cout << endl;
    // for(auto i : issues)
    //     cout << i << ' ';

    for(int i = 0 ; i < m ; i++)
    {
        if(freq[problems[i]] == 0)
            problems[i] = -1;
    }
    sort(problems,problems+m);
    for(int i = 0 ; i < issues.size() ; i++)
    {
        int l = 0;
        int r = m -1;
        while(l < r)
        {
            int mid = l + (r - l)/2;
            if(problems[mid] < issues[i])
                l = mid + 1;
            else
                r = mid;
        }
        if(problems[r] > issues[i])
        {
                problems[r] = issues[i] = -1;
                sort(problems,problems+m);
        } 
    }

    int cnt = 0;
    for(int i = 0 ; i < issues.size() ; i++)
    {
        if(issues[i] > 0)
            cnt++;
    }

    cout << endl << cnt << endl;
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