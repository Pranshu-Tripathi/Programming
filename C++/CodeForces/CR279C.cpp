#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

int po[1000001];

void po10(int n,ll b)
{
    po[n-1] = 1;
    for(int i = n - 2 ; i >= 0 ; i--)
        po[i] = (po[i+1] *10)%b;
}


void _run()
{
    string num;
    cin >> num;
    ll a,b;
    cin >> a >> b;
    int n = num.length();
    po10(n,b);
    ll rem_a[n],rem_b[n];
    rem_a[0] = (num[0]-'0')%a;
    rem_b[n-1] = (num[n-1] - '0') % b;
    int x = 1, y = n - 2;
    while(x < n && y >= 0)
    {
        rem_a[x] = ((rem_a[x-1] * 10)%a + (num[x] - '0') % a)%a;
        rem_b[y] = (( (ll)po[y] % b * (num[y] - '0') % b) % b + rem_b[y+1]  % b)%b;
        x++,y--;
    }
    int j = -1;
    for(int i = 0 ; i < n - 1 ; i ++)
    {
        if(rem_a[i] == 0)
            if(rem_b[i+1] == 0 && num[i+1] != '0')
            {
                j = i;
                break;
            }
    }

    if(j == -1)
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    for(int i = 0 ; i <= j ; i++)
        cout << num[i];
    cout << endl;
    for(int i = j + 1  ; i < n ; i++)
        cout << num[i];
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
