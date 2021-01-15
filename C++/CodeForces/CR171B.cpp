#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n;
    ll t;
    cin >> n >> t;
    vector<int> books(n+1);
    books[0] = -1;
    int pre[n+1];
    pre[0] = 0;
    for(int i = 1 ; i <= n ;i++)
    {
        cin >> books[i];
    }

    for(int i = 1 ; i <= n ; i++)
        pre[i] = pre[i-1] + books[i];
    
    // for(auto x  : pre)
    //     cout << x << " ";
    // cout << endl;

    if(pre[n] <= t)
    {
        cout << n << endl;
        return;
    }
    int ans = -2;
    for(int left = 1 ; left <= n ; left++)
    {
        if(books[left] > t)
            continue;
        int l = left;
        int r = n;
        while(l < r)
        {
            int mid = l + (r-l)/2;
            mid++;
            if(pre[mid] - pre[left-1] <= t)
                l = mid;
            else
                r = mid - 1;
        }
        ans = max(ans,l - left + 1);
    }
    cout << (ans == -2 ? 0 : ans);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    while(test--)
        _run();
    return 0;
}
