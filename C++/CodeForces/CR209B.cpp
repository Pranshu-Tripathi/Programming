#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n,k;
    cin >> n >> k;
    int arr[2 * n + 1];
    for(int i = 1 ; i <= 2 * n ; i++)
        arr[i] = i;
    
    int i = 1;
    while(k-- && i <= 2 * n - 2)
    {
        swap(arr[i],arr[i+2]);
        i += 4;
    }

    for(int i = 1 ; i <= 2 * n ; i++)
        cout << arr[i] << ' ';
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
