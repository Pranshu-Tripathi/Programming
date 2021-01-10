#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n;
    cin >> n;
    int a[n+1];
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i];
    int k =0;
    int idx = -1;

    for(int i = 2 ; i <= n ; i++)
    {
        if(a[i-1] > a[i])
        {
            k++;
            idx = i;
        }
        if(k >= 2)
            break;
    }

    if(k == 0)
        cout << 0 << endl;
    else if(k==1 && a[1] >= a[n])
        cout << n - idx + 1;
    else
        cout << -1 << endl;
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
