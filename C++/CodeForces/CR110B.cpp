#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi 3.1415926536

void _run()
{
    ll n;
    cin >> n;
    ll radii[n];
    for(int i = 0 ; i < n ; i++)
        cin >> radii[i];
    sort(radii,radii+n);
    double area = 0.0;

    for(int i = n - 1 ; i >= 0 ; i-=2)
    {
        double radiusSquare = radii[i] * radii[i];
        area += (pi * radiusSquare);
    }

    for(int i = n -2 ; i >= 0 ; i -= 2)
    {
        double radiusSquare = radii[i] * radii[i];
        area -= (pi * radiusSquare);
    }

    cout << area  << endl;
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