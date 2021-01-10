#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n;
    cin >> n;
    ll a[n];
    ll b[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i] , b[i] = a[i];
    
    sort(b,b+n);

    int sr = -1, en = -1;

    for(int i = 0 ; i < n ; i++)
    {
        if(a[i] != b[i])
        {
            sr = i;
            break;
        }
    }

    for(int i = n -1 ; i >= 0 ; i--)
    {
        if(a[i] != b[i])
        {
            en = i;
            break;
        }
    }

    if(sr == -1 && en == -1)
    {
        cout << "yes" << endl;
        cout << 1 << " " << 1 << endl;
        return;
    }

    for(int i = sr ; i < en ; i++)
    {
        if(a[i] < a[i+1])
        {
            cout << "no" << endl;
            return;
        }
    }

    cout << "yes" << endl;
    cout << sr +1 << " " << en+1 << endl;
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
