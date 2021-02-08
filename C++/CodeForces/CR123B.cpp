#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n ,m;
    cin >> n >> m;
    int x = min(n,m);
    int pat[x+1];
    if(m %2 != 0)
    {
        
        pat[1] = (m+1)/2;
        for(int i = 3 ; i <= x ; i+=2)
            pat[i] = pat[i-2] + 1;
        pat[2] = (m+1)/2 - 1;
        for(int i = 4 ; i <= x ; i+=2)
            pat[i] = pat[i-2] - 1;
    }
    else
    {
        pat[1] = (m+1)/2;
        pat[2] = (m+1)/2+1;
        for(int i = 3 ; i <= x ; i +=2)
            pat[i] = pat[i-2]  - 1;
        for(int i = 4;  i <= x ; i+= 2)
            pat[i] = pat[i-2] + 1;
    }
    if(n == min(n,m))
    {
        for(int i = 1 ; i <= n ; i++)
        {
                cout << pat[i] << endl;
        }
    }

    else
    {
        int j = 1;
        while(n--)
        {
            if(j == m+1)
                j = 1;
            cout << pat[j] << endl;
            j++;            
        }
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
