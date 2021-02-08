#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int d,n;
    cin >> d >> n;
    int a[n];
    int manula = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        if(i != 0)
        {
            manula += d - a[i-1];
        }
    }

    cout << manula << endl;
}

int main()
{
    fast;
    int test = 1;
    while(test--)
        _run();
    return 0;
}
