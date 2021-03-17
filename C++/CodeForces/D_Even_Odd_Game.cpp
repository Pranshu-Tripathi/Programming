#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double

const string bob = "Bob";
const string ali = "Alice";
const string te = "Tie";
vector<ll> a;
void _run()
{
    a.clear();
    int n;
    cin >> n;
    ll t;
    for(int i =0 ;i < n ; i++)
    {
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(),a.end(),greater<ll>());
    ll al=0,b=0;    
    int idx = 0;
    bool at = true;
    while(idx < a.size())
    {
        if(at)
        {
            if(a[idx] %2==0)
                al+=a[idx];
            at = !at;
        }
        else
        {
            if(a[idx]%2 != 0)
                b += a[idx];
            at = !at;
        }
        idx++;
    }


    if(al < b)
        printf("Bob\n");
    else if(al > b)
        printf("Alice\n",ali);
    else 
        printf("Tie\n",te);
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
