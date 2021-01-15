#include<bits/stdc++.h>
using namespace std;
#define ll long long

void _run()
{
    int n,k;
    cin >> n >> k;
    int a[n+1];
    a[0] = -1;
    a[1] = 1;
    for(int i = 2 ; i <= n ; i++)
    {
        if(i <= k)
            a[i] = a[i-1] + 1;
        else
            a[i] = a[i-1] - 1;
    }


    int y = a[n];
    for(int i = 1 ; i < y ; i++)
        cout << i << ' ';
    
    for(int i = k ; i >= y ; i--)
        cout << i << ' ';

    cout << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}