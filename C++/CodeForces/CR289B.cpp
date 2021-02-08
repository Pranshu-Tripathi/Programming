#include<bits/stdc++.h>
using namespace std;

#define ll long long

void _run()
{
    int n,k;
    cin >> n >> k;
    int piles[n];
    int mx = -1;
    int mi = __INT_MAX__;
    for(int i =0 ; i < n ; i++)
        cin >> piles[i], mx < piles[i] ? mx = piles[i] : mx = mx ,mi > piles[i] ? mi = piles[i] : mi = mi;
    
    if(mx - mi > k)
    {
        cout << "NO" << endl;
        return;
    }

    vector<vector<int>> ans(n);

    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j  < mi ; j++)
        {
            ans[i].push_back(1);
        }
        piles[i] -= mi;
    }

    for(int i = 0 ; i < n ; i++)
    {
        int left = piles[i];
        int j = 2;
        while(left--)
        {
            ans[i].push_back(j),j++;
            if(j > k)
                j = 1;
        }
    }

    cout << "YES" <<endl;

    for(int i = 0 ; i < n ; i++)
    {
        for(int j : ans[i])
            cout << j << ' ';
        cout << endl;
    }
}

int main()
{
    int test = 1;
    while(test--)
        _run();
    return 0;
}