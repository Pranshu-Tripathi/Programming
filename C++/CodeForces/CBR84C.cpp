#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n;
    cin >> n;
    string s = "";
    while(n > 0)
    {
        
        if(n % 7 == 0)
        {
            n -= 7;
            s += '7';
        }
        else 
        {
            n -= 4;
            s += '4';
        }
    }

    if(n != 0)
        cout << -1 << endl;
    else 
        cout << s << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
