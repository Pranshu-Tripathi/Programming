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
    int n,k;
    cin >> n >> k;
    int h[n+1];
    for(int i = 1 ; i <= n ; i++)
        cin >> h[i];

    int days = n+10;
    for(int final_col = 1 ; final_col <= *max_element(h+1,h+n+1) ; final_col++)
    {
        
        int res = 0;
        for(int i = 1 ; i <= n ; i++)
        {
            if(h[i] != final_col)
            {
                res++;
                i += k - 1;
            }
        }
        days = min(days,res);
    }
    cout << days << endl;
    
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
