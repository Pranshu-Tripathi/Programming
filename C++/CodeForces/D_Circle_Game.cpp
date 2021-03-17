#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "Ashish" << endl
#define cn cout << "Utkarsh" << endl
#define ld long double
#define mod 1000000009

bool check(int x,int y,int d)
{
    return pow(x,2)+pow(y,2) <= pow(d,2);
}


void _run()
{    
    int d,k;
    cin >> d >> k;
    int moves = 0 ;
    int x = 0;
    int y = 0;
    bool t = true;
    while(1)
    {
        if(t)
        {
            x += k;
            t = ! t;
        }
        else
        {
            y += k;
            t =! t;
        }
        if(x > d || y > d || pow(x,2)+pow(y,2) > pow(d,2))
            break;
        moves++;
    }
    if(moves % 2 != 0)  
        cy;
    else
        cn;
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
