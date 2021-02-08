#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

// n - zeroes
// m - ones

void _run()
{
    int n , m;
    cin >> n >> m;
    if(m < n - 1 || m > 2 * (n + 1))
    {
        cout << -1 << endl;
        return;
    } 
    int arr[3*n+3];
    memset(arr,-1,sizeof(arr));
    int idx = 0;
    for(int i = 3 ; i <= 3 * n + 2 ; i+=3)
    {
        arr[i] = 0;
        idx  = i;
    }
    for(int i = 4 ; i <= idx ; i+=3)
        arr[i] = 1,m--;
    for(int i = 1 ; i <= 3 * n + 2 ; i++)
    {
        if(m == 0)
            break;
        if(arr[i] == -1)
        {
            arr[i] = 1;
            m--;
        }
    }
    for(int i = 1 ; i <= 3 * n + 2 ; i++)
    {
        if(arr[i] != -1)
            cout << arr[i];
    }
    cout << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
