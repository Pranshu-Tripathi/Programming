#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double

void _run()
{
    int n;
    cin>>n;
    int a;
    int cnt[3]={0};
    for(int i=0 ;  i <n ;i++)
    {
        cin>>a;
        cnt[a%3]++;
    }
    int ans = 0;
    int one = n/3;
    int buf;
    int idx=0;
    while(1)
    {
        if(cnt[0]==one && cnt[1]==one && cnt[2]==one)
        {
            break;
        }
        if(cnt[idx] > one)
        {
            buf = cnt[idx] - one;
            ans += buf;
            cnt[idx] -= buf;
            idx++;
            idx %= 3;
            cnt[idx] += buf;
        }
        else
        {
            idx++;
            idx %= 3;
        }
    }
    cout<<ans<<endl;
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
