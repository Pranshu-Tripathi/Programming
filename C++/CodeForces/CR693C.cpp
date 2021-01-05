#include<bits/stdc++.h>
using namespace std;

void _run()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i =0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    int index;
    vector<int> dp(n,0);
    for(int i = n-1 ; i >= 0 ; i--)
    {
        index = i;
        dp[i] = arr[i];
        index += arr[i];
        if(index < n)
            dp[i] += dp[index];
    }

    cout << *max_element(dp.begin(),dp.end()) << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}