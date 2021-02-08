#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(false); \
                cin.tie(NULL)


void  _run()
{

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
    cin >> n >> k;
    int a[n+1],b[n+1];
    a[0] = b[0] = 0;
    for(int i = 1 ; i <= n ; i++)
        cin >> a[i] , b[i] = a[i];
    
    sort(b,b+n+1);
    cout << b[n-k+1] << endl;

    for(int i = n ; i >= n - k + 1; i--)
    {
        for(int j = 1 ; j <= n ; j++)
        {
            if(a[j] == b[i] )
            {
                cout << j << ' ';
                a[j] = -1;
                break;
            }
        }
    }

}

int main()
{
    fast;
    int test = 1;
    while(test--)
        _run();
    return 0;
}