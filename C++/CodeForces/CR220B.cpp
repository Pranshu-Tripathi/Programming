#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

int dig(char c)
{
    return c - '0';
}

void _run()
{
    string num;
    cin >> num;
    ll ans = 1;
    int array[num.length()];
    for(int i = 0 ; i < num.length() - 1; i++) 
    {
        if(abs(dig(num[i]) + dig(num[i+1])) == 9)
        {
            int cnt = 1;
            //cout << dig(num[i]) << ' ' << dig(num[i+1]) << endl;
            for(int j = i + 1 ; j < num.length() ; j++)
            {
                if( abs(dig(num[j]) + dig(num[j-1])) == 9 )   
                    cnt++;
                else
                    break;
            }
            //cout << cnt << endl;
            if(cnt % 2 != 0)
                ans *= (cnt/2+1);
            i += cnt -1;
        }
    }

    cout << ans << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
