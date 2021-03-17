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
    ll n;
    cin >> n;
     if( n > 3)
     {
        if(n % 2 == 0)
            cout << 2 << endl;
        else
            cout << 3 << endl;
     }
     else
     {
         switch (n)
         {
         case 1:
            cout << 0 << endl;
            break;
         case 2 : 
            cout << 1  << endl;
            break;
        case 3 :
            cout << 2 << endl;
            break; 
         default:
             break;
         }
     }
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
