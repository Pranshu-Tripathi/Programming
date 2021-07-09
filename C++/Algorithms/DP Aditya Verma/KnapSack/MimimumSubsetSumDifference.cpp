#include<bits/stdc++.h>
using namespace std;

int minimumSubsetSum(vector<int>& a, int n, int sum)
{
    bool dp[n+1][sum+1];
    memset(dp,false,sizeof(dp));
    for(int  i=  0 ; i <= n ; i++)
        dp[i][0] = true;
    
    for(int i = 1 ; i <= n;  i++)
    {
        for(int j = 1 ; j <= sum ; j++)
        {
            dp[i][j] = dp[i][j] || dp[i-1][j];
            if(a[i-1] <= j)
                dp[i][j] = dp[i-1][j-a[i-1]] || dp[i][j];
        }
    }

    vector<int> pos;
    for(int i = 0 ; i <= sum ; i++)
        if(dp[n][i])
            pos.push_back(i);
    
    int ans = sum;
    for(int i = 0 ; i < pos.size(); i++)
        ans = min(ans, abs(sum - 2 *pos[i]));
    return ans;
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i], sum += arr[i];
    cout << minimumSubsetSum(arr,n,sum);
}