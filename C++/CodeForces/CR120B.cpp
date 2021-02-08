#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    ll x1,y1,r1,x2,y2,r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2 ;
    long double dist_centers = sqrt((x1 - x2) * (x1 - x2) + (y1-y2) * (y1-y2));
    long double radius = dist_centers - r1 - r2;
    if(radius < 0)
    {
        if(r1 > r2)
        {
            radius = r1 - dist_centers-r2;
        }
        else
        {
            radius = r2 - dist_centers - r1;
        }
    }
    cout.precision(20);
    if(radius < 0)
        cout << 0 << endl;
    else 
        cout << radius/2 << endl; 
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
