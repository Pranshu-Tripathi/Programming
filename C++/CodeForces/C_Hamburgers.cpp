#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

void _run()
{
    string recipie;
    cin >> recipie;
    int ex_b,ex_s,ex_c;
    cin >> ex_b >> ex_s >> ex_c;
    int pr_b,pr_s, pr_c;
    cin >> pr_b >> pr_s >> pr_c;
    ll rubles;
    cin >> rubles;
    int co_b=0,co_s=0,co_c=0;
    for(int i = 0 ; i < recipie.length() ; i++)
    {
        if(recipie[i] == 'B')
            co_b++;
        else if(recipie[i] == 'S')
            co_s++;
        else
            co_c++;
    }
    
    ll l = 0 ; ll r = 100000000000001;
    ll rubles1 = rubles;
    ll mid;
    while(l <= r)
    {
        rubles1 = rubles;
        mid = (l+r)/2;
        ll rubles_b = max((ll)0, ((mid* co_b) - ex_b)  * pr_b);
        ll rubles_s = max((ll)0, ((mid*co_s)-ex_s) * pr_s);
        ll rubles_c = max((ll)0, ((mid*co_c) - ex_c) * pr_c);
        rubles1 -= (rubles_b+rubles_c + rubles_s);
        if(rubles1 > 0)
            l = mid+1;
        else if(rubles1 < 0)
            r = mid - 1;
        else
            break;
    }
    if(rubles1 < 0) 
        mid--;
    cout << mid;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}