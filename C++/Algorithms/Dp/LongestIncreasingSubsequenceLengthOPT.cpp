/*
O(NlogN) solution.
Apporah :- 
    Choosing and saving best candidates available for the future members that are checked in the array
*/


#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0) , cin.tie(0),cout.tie(0);
#define LOG(X)      cout << x << endl;
#define ll long long
#define endl "\n"
#define And &&
#define Or ||
#define FOR(i,a,b)              for(int i = a; i < b; i++)
#define REV(i,a,b)              for(int i = a; i >= b; i--)
#define FORE(i,a,b)             for(int i = a; i <= b; i++)
#define pii                     pair<int,int>
#define pll                     pair< long long int, long long int> 
typedef 						long double ld;
typedef 						unsigned long long ull;
#define F                       first
#define S                       second
#define pb                      push_back


int getBestCandidate(map<ll,int> & candidates, ll v)
{
    auto it = candidates.lower_bound(v);
    if(it == candidates.begin())    return 0;
    
    it--;
    return it->S; 
}


void insert(map <ll,int> & candidates , int val , int adv)
{
    if(candidates[val] >= adv)    return;
    candidates[val] = adv;

    auto cleaner = candidates.find(val);
    cleaner++;
    while(cleaner != candidates.end() && cleaner->S <= adv)
    {
        auto te = cleaner;
        cleaner++;
        candidates.erase(te);
    } 
}

ll solve(int n, ll arr[])
{

    int dp[n];
    dp[0] = 1;
    map <ll,int> candidates;

    candidates[arr[0]] = dp[0];

    for(int i = 1 ; i < n ; i++)
    {
        dp[i] = 1 + getBestCandidate(candidates,arr[i]);
        insert(candidates,arr[i],dp[i]);
    }

    return *max_element(dp,dp+n);
}

int main()
{
    int n;
    cin >> n;
    ll arr[n];
    int i;
    FOR(i,0,n)  cin >> arr[i];


    cout << solve(n,arr);
}