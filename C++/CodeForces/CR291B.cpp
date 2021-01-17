#include<bits/stdc++.h>
using namespace std;

#define ll long long

void _run()
{
    int n,x0,y0;
    cin >> n  >> x0 >> y0;
    set<double> slopes;
    int x,y;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> x >> y;
        if(x == x0)
        {
            slopes.insert(__INT_MAX__);
            continue;
        }
        double ys = y - y0;
        double xs = x - x0;
        double slop = ys/xs;
        slopes.insert(slop);
    }


    cout << slopes.size();

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;
    while(test--)
        _run();
    return 0;
}