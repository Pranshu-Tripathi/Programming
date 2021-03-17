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


void _run()
{    
    int n;
    cin >> n;
    int a[n];
    ll sum = 0;
    int fre[200005];
    memset(fre,0,sizeof(fre));
    for(int i = 0 ; i < n ; i++)
        cin >> a[i], fre[a[i]]++, sum += a[i];
    
    int moves = n - 1;
    for(int fele = n  ; fele > 0 ; fele--)
    {
        if(sum % fele == 0)
        {
            int ops = n - fele;
            int fval = sum/fele;
            int cnt = 0;
            bool posi = true;
            int s = 0;
            if(fval < 200005)
                if(fre[fval] == fele)
                    moves = 0;
            
            for(int i = 0 ; i < n ; i++)
            {
                if(s > fval)
                {
                    posi = false;
                    break;
                }
                if(a[i] == fval)
                {
                    if(s == fval)
                        cnt+=2,s=0;
                    else if(s == 0)
                        cnt++;
                    else
                    {
                        posi = false;
                        break;
                    }
                } 
                else
                {
                    if(s == fval)
                    {
                        cnt++;
                        s = 0;
                    }
                    s += a[i];
                }  
                //cout << s << ' ' << cnt << endl;
            }
            if(s == fval)
            {
                cnt++;
            }
            if(posi && cnt == fele)
                moves = min(moves,ops);
            //cout << "--------------------" << endl; 
        }
    }
    cout << moves << endl;
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
