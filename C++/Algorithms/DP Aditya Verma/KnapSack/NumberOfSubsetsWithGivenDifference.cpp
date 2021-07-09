#include<bits/stdc++.h>
using namespace std;

int countSubsets(vector<int>& a, int n, int sum, int target)
{
    if(target > sum or target < 0) 
        return 0;
    int dp[n+1][sum+1];
    memset(dp,0,sizeof(dp));
    for(int i = 0 ; i <= n;  i++)
        dp[i][0] = 1;
    
    for(int  i= 1 ; i <= n ; i++)
    {
        for(int j = 1 ; j <= sum ; j++)
        {
            dp[i][j] += dp[i-1][j];
            if(a[i-1] <= j)
                dp[i][j] += dp[i-1][j-a[i-1]];
        }
    }

    int ans = 0;

    for(int i = 0 ;  i <= sum ;  i++)
        cout << dp[n][i] << ' ';
    cout << endl;

    for(int i = 0 ; i <= sum ; i++)
    {
        if(i - target >= 0 and 2 * i == sum + target)
        {
            cout << '%' << i << endl;
            ans += dp[n][i] ;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int target;
    cin >> target;
    int sum = 0;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i], sum += arr[i];
    cout << countSubsets(arr,n,sum,target);
}