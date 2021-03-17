#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000009

void _run()
{    
    int n;
    cin >> n;
    int arr[n+1];
    int x = n;
    for(int i = 1 ; i <= n ; i++)
    {
        arr[i] = x;
        x--;
    }

    if(n % 2 != 0)
        swap(arr[(n+1)/2],arr[(n+1)/2 + 1]);
    
    for(int i = 1 ; i <= n ; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

int main()
{
    fast;
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
