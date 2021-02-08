#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int aboys,bgirls,k;
    cin >> aboys >> bgirls >> k;

    int boys[k];
    int girls[k];
    for(int i = 0 ; i<k ; i++)
        cin >> boys[i];
    for(int i = 0 ; i < k ; i++)
        cin >> girls[i];

    int freqB[200005];
    int freqG[200005];
    memset(freqB,0,sizeof(freqB));
    memset(freqG,0,sizeof(freqG));

    for(int i = 0 ; i < k ; i++)
        freqB[boys[i]]++,freqG[girls[i]]++;

    
    ll ans = 0;
    for(int i = 0 ; i < k ; i++)
    {
        int x = k -i;
        int pairposs = x - freqB[boys[i]];
        //cout << pairposs << '#' << endl;
        pairposs -= (freqG[girls[i]] - 1);
        //cout << pairposs << '&' << endl;
        ans += (pairposs > 0) ? pairposs : 0;
        freqB[boys[i]]--;
        freqG[girls[i]]--;
        //cout << pairposs << '%' << endl;
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
