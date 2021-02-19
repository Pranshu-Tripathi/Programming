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
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if(x1 == x2)
    {
        int x3 = x1+abs(y2-y1);
        cout << x3 << ' ' << y1 << ' ';
        cout << x3 << ' ' << y2 << ' ';
        return; 
    }
    if(y1 == y2)
    {
        int y3 = y1 + (abs(x1-x2));
        cout << x1 << ' ' << y3 << ' ';
        cout << x2 << ' ' << y3 << ' ';
        return;
    }

    if(abs(x1-x2) == abs(y2-y1))
    {
            int x3 = x1;
            int y3 = y2;
            int x4 = x2;
            int y4 = y1;
            cout << x3 << ' ' << y3 << ' ';
            cout << x4 << ' ' << y4 << ' ';
            return;
    }

    cout << -1 << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
