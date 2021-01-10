#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int r,x,y,x1,y1;
    cin >> r >> x >> y >> x1 >> y1;
    if(x==x1 && y==y1)
    {
        cout << 0 << endl;
        return;
    }

    double xc = pow(x-x1,2);
    double yc = pow(y-y1,2);
    double d = sqrt(xc+yc);

    cout << ceil(d/(2*r));

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    while(test--)
        _run();
    return 0;
}
