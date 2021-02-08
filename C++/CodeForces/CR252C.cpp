#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n,m,k;
    cin >> n >> m >> k;
    int tubelen = (n*m)/k;
    int updowntrack = 1;
    int x = 1, y = 1;
    
    for(int i = 1 ;  i <= k ; i++)
    {
        if(i == k)
            tubelen += (n*m)%k;
        cout << tubelen << ' ';
        for(int j = 1;  j <= tubelen ; ++j)
        {
            cout << x << ' ' << y << ' ';
            y += updowntrack;
            if(y > m)
                x++, updowntrack = -1,y=m;
            else if(y < 1)
                x++, updowntrack = 1, y = 1;
        }
        cout << endl;
    }

}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
