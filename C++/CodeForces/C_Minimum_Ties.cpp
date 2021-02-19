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
        int n; cin >> n;
		int cnt[n+1];
		memset(cnt, 0, sizeof(cnt));
		int mx = (n-1)/2;
		for(int i = 1; i <= n; i++)
		{
			for(int j = i+1; j <= n; j++)
			{
				if(i+n/2 == j and n%2 == 0)
				{
					cout << 0 << " ";
				}
				else if(cnt[i] < mx)
				{
					cnt[i]++;
					cout << 1 << " ";
				}
				else if(cnt[j] < mx)
				{
					cnt[j]++;
					cout << -1 << " ";
				}
			}
		}
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
