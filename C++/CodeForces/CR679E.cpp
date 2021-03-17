#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

ll ncr[1001][1001];
bool vis[1001][1001];
int freq[1001];
int inansFreq[1001];

ll getNCR(int n, int r)
{
    if(vis[n][r])
    {
        return ncr[n][r];
    }
    else if(r == 0 || r == 1)
    {
        vis[n][r] = true;
        ncr[n][r] = n;
    }
    else if(n == 0)
    {
        vis[n][r] = true;
        ncr[n][r] = 0;
    }
    else 
    {
        vis[n][r] = true;
        ncr[n][r] = (getNCR(n-1,r)  % mod + getNCR(n-1,r-1) % mod) % mod;
    }
    return ncr[n][r];
}




void _run()
{
    int n,k;
    cin >> n >> k;
    memset(freq,0,sizeof(freq));
    memset(inansFreq,0,sizeof(inansFreq));
    vector<int> fol(n);
    set<int> ele;
    for(int i = 0 ; i < n ; i++)
        cin >> fol[i], freq[fol[i]]++;
    
    sort(fol.begin(),fol.end(),greater<int>());

    for(int i = 0 ; i < k ; i++)
    {
        inansFreq[fol[i]]++;
        ele.insert(fol[i]);
    }

    ll ans = 1;
    for(int x : ele)
    {
        //cout << x << ' ' << freq[x] << ' ' << inansFreq[x] << endl;
        ans *= getNCR(freq[x],inansFreq[x]);
    }

    cout << ans % mod << endl;
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
