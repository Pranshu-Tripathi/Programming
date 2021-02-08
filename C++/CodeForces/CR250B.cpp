#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

int factor(int n)
{
    int ans = 1;
    while(n % 2 == 0)
    {
        ans*=2;
        n/=2;
    }
    return ans;
}

bool secondSort(const pair<int,int>& a , const pair<int,int>& b)
{
    return a.second > b.second;
}

void _run()
{
    int sum, limit;
    cin >> sum >> limit;
    vector<pair<int,int>> even;
    vector<int> odd;
    set<int> seq;

    for(int  i = 1 ; i <= limit ; i++)
    {
        if(i % 2 == 0)
        {
            even.push_back({i,factor(i)});
        }
        else
        {
            odd.push_back(i);
        }
    }

    sort(even.begin(),even.end(),secondSort);

    for(int i = 0 ; i < even.size() ; i++)
    {
        if(sum == 0)
            break;
        if(sum - even[i].second >= 0)
        {
            seq.insert(even[i].first);
            sum -= even[i].second;
        }
    }
    for(int i = 0 ; i< odd.size() ; i++)
    {
        if(sum == 0)
            break;
        sum--;
        seq.insert(odd[i]);
    }
    
    if(sum != 0)
    {
        cout << -1 << endl;
        return;
    }

    cout<< seq.size() <<endl;

    for(int x : seq)
    {
        cout << x << ' ';
    }
    cout << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
