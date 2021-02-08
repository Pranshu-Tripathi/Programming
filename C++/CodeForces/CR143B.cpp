#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n,d,l;
    cin >> n >> d >> l;
    int seq[n+1];
    int evnpos = n/2;
    int oddpos = n - n/2;
    int minsumodd = 1 * (oddpos);
    int maxsumodd = l * (oddpos);
    if(evnpos * 1 + d > maxsumodd || evnpos * l + d < minsumodd)
    {
        cout << -1 << endl;
        return;
    }

    for(int i = 1 ; i <= n ; i += 1)
        seq[i] = 1;
    
    int odd = n - n/2;
    int even = n / 2;
    
    if(d <= 0)
    {
        for(int i = 2 ; i <= n ; i += 2)
        {
            if(odd == even + d)
                break;
            while(seq[i] < l)
            {
                even++;
                seq[i]++;
                if(odd == even+d)
                    break;
            }
        }
    }
    else
    {
        for(int i = 1 ; i <= n ; i += 2)
        {
            if(odd == even + d)
                break;
            while(seq[i] < l)
            {
                odd++;
                seq[i]++;
                if(odd == even+d)
                    break;
            }
        }
    }


    for(int i = 1 ; i <= n ; i++)
        cout << seq[i] << ' ';
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
