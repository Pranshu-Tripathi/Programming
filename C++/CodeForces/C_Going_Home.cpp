/*
PR7
*/
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
#define debug(a...) cout<<#a<<": ";for(auto it:a)cout<<it<<" ";cout<<endl;

map<ll,pair<int,int>> freq; // making pairs of all sums

void _run()
{    
    freq.clear();
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = i + 1  ; j < n ; j++)
        {
            if(freq.find(a[i] + a[j]) == freq.end())
            {
                freq[a[i]+a[j]] = {i,j};
            }
            else
            {
                if(freq[a[i]+a[j]].first != i && freq[a[i]+a[j]].second != j && freq[a[i]+a[j]].second != i && freq[a[i]+a[j]].first != j)
                {
                    cy;
                    cout << i + 1 << ' ' << j+1 << ' '  << freq[a[i]+a[j]].first + 1 << ' ' << freq[a[i]+a[j]].second +1 << endl;
                    return;
                }
            }
        }
    }

    cn;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
