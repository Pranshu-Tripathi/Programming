#include<bits/stdc++.h>
using namespace std;
#define ll long long

void _run()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];
    int mx = -1;
    for(int i = 0 ;i  < n ; i++)
    {
        int pre = 0;
        int suf = 0;
        for(int j = i -1 ; j >= 0 ; j--)
        {
            if(a[j] > a[j+1])
                break;
            pre++;
        }
        for(int j = i + 1 ; j < n ; j++)
        {
            if(a[j] > a[j-1])
                break;
            suf++;
        }
        mx = max(mx,pre + suf + 1);
    }
    cout << mx;
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