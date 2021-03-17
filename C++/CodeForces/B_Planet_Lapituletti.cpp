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
int h,m;
string s;

int getHr(int * mi)
{
    int M[2];
    for(int i = 0 ; i < 2 ; i++)
    {
        if(mi[i] == 2)
            M[i] = 5;
        else if(mi[i] == 5)
            M[i] = 2;
        else
            M[i] = mi[i];
    }

    int mx = M[1] * 10 + M[0];
    return mx;
}

int getMi(int * hr)
{
    int H[2];
    for(int i = 0 ; i < 2 ; i++)
    {
        if(hr[i] == 2)
            H[i] = 5;
        else if(hr[i] == 5)
            H[i] = 2;
        else
            H[i] = hr[i];
    }

    int hx = H[1] * 10 + H[0];
    return hx;
}


bool containsRightDigits(int * hr, int * mi)
{
    for(int i = 0 ; i < 2 ; i++)
        if(hr[i] != 1 && hr[i] != 2 && hr[i] != 8 && hr[i] != 5 && hr[i] != 0)
            return false;
    for(int i = 0 ; i < 2 ; i++)
        if(mi[i] != 1 && mi[i] != 2 && mi[i] != 8 && mi[i] != 5 && mi[i] != 0)
            return false;
    return true;
}


bool validTime(int * hr, int * mi)
{
    if(!containsRightDigits(hr,mi))
        return false;
    int hm = getHr(mi);
    int mm = getMi(hr);

    if(hm > h - 1 || mm > m - 1)
        return false;
    else 
        return true;
}

void incrementTime(int * hr, int * mi)
{
    int hx = hr[0] * 10 + hr[1];
    int mx = mi[0] * 10 + mi[1];
    mx++;
    if(mx == m)
    {
        hx++;
        mx = 0 ;
    }
    if(hx == h)
    {
        hx = 0;
    }

    hr[0] = hx/10;
    hr[1] = hx%10;
    mi[0] = mx/10;
    mi[1] = mx%10;
    // cout << "TIME :";
    // for(int i = 0 ; i < 2 ; i++)
    //     cout << hr[i];
    // cout << ':';
    // for(int i = 0 ; i < 2 ; i++)
    //     cout << mi[i];
    // cout << endl;
}

void _run()
{    

    cin >> h >> m;
    cin >> s;
    int hr[2],  mi[2];
    int ps;
    for(ps = 0 ; s[ps] != ':' ;ps++)
    {
        hr[ps] = s[ps] - '0';
    }
    for(int j = ps +1 ; j < s.length() ; j++)
    {
        mi[j-ps-1] = s[j] - '0'; 
    }

    while(true)
    {
        if(validTime(hr,mi))
        {
            break;
        }
        incrementTime(hr,mi);
    }
    //cout << "ANS :";
    for(int i = 0 ; i < 2 ; i++)
        cout << hr[i];
    cout << ':';
    for(int i = 0 ; i < 2 ; i++)
        cout << mi[i];
    cout << endl;
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
