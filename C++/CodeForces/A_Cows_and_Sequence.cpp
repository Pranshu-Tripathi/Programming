#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double

ld lazy[200001] = {0.0};
int cur_n = 1;
ld cur_avg = 0.0;

void _add()
{
    ll a;
    ld x;
    cin >> a >> x;
    cur_avg += (a* x);
    lazy[a] += x;
}

void _add_element()
{
    int ai;
    cin >> ai;
    cur_avg += ai;
    cur_n++;
    lazy[cur_n - 1] -= ai;
    lazy[cur_n] = ai; 
    
}

void _delete_element()
{
    cur_n--;
    lazy[cur_n ] += lazy[cur_n+1];
    cur_avg -= lazy[cur_n+1]; 
    lazy[cur_n+1] = 0.0;
}

void _calculate_current_average()
{
    ld avg = cur_avg/(ld)cur_n;
    cout.precision(20);
    cout << avg << endl;
}

void _run()
{
    int ops;
    cin >> ops;
    int type;
    while(ops--)
    {
        cin >> type;
        if(type == 1)
            _add();
        else if(type == 2)
            _add_element();
        else
            _delete_element();
        _calculate_current_average();
    }
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
