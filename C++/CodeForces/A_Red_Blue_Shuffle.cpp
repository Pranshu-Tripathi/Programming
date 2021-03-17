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

const string red = "RED";
const string blue = "BLUE";
const string eq = "EQUAL";

void _run()
{    
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    int cnta = 0,cntb = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] > b[i])
            cnta++;
        else if(a[i] == b[i])
            cnta++,cntb++;
        else
            cntb++;
    }

    if(cnta > cntb) 
        cout << red << endl;
    else if(cnta < cntb)
        cout << blue << endl;
    else
        cout << eq << endl;
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
