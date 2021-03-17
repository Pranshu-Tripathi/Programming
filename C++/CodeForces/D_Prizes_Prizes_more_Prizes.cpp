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

void _run()
{
    int n;
    cin >> n;
    ll p[n];
    ll a[5] = {0};
    ll b[5];
    for(int i = 0 ; i < n ; i++)
        cin >> p[i];
    for(int i = 0 ; i < 5 ; i++)
        cin >> b[i];
    int pts = 0;

    for(int i = 0 ; i < n ; i++)
    {
        pts += p[i];
        //cout<< "Current Points : " << pts << endl;
        if(pts >= b[4])
        {
            ll fre = pts/b[4];
            a[4] += fre;
            pts -= fre * b[4];
        }
        if(pts >= b[3])
        {
            ll fre = pts/b[3];
            a[3] += fre;
            pts -= fre * b[3];
        }
        if(pts >= b[2])
        {
            ll fre = pts/b[2];
            a[2] += fre;
            pts -= fre * b[2];
        }
        if(pts >= b[1])
        {
            ll fre = pts/b[1];
            a[1] += fre;
            pts -= fre * b[1];
        }
        if(pts >= b[0])
        {
            ll fre = pts/b[0];
            a[0] += fre;
            pts -= fre * b[0];
        }
    }
    for(int i =  0 ; i < 5 ; i++)
        cout << a[i] << ' ';
    cout << endl;
    cout << pts;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
