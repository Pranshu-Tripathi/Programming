#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

bool diglessk(ll x,int k)
{
    vector<int> dig;
    while(x)
    {
        dig.push_back(x%10);
        x /=10;
    }
    sort(dig.begin(),dig.end());
    for(int j = 0 ; j <= k ; j ++)
    {
        bool found = false;
        for(int i = 0 ; i < dig.size() ; i ++)
        {
            if(dig[i] == j)
            {
                found = true;
                break;
            }
        }

        if(!found)
            return false;
    }
    return true;
}

void _run()
{
    int n,k;
    cin >> n >> k;
    int co = 0;
    ll a[n];
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
        if(diglessk(a[i],k))
            co++;
    }
    cout << co << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
