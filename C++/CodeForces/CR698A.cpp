#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n;
    cin >> n;
    int a[n];
    int frq[101];
    memset(frq,0,sizeof(frq));
    int maxfreq = -1;
    for(int i = 0 ; i < n ; i ++)
    {
        cin >> a[i];
        frq[a[i]]++;
        if(frq[a[i]] > maxfreq)
            maxfreq = frq[a[i]];
    }

    cout << maxfreq << endl;
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
