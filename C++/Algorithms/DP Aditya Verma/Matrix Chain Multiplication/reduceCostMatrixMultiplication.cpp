#include<bits/stdc++.h>
using namespace std;

int MCM(vector<int>& a, int i, int j)
{
    if(i >= j)
        return 0;
    int ans = INT_MAX;
    for(int  k = i ;  k <= j-1 ; k++)
    {
        int temp = MCM(a,i,k) + MCM(a,k+1,j) + a[i-1] * a[k] * a[j];
        ans = min(ans,temp);
    }
    return ans;
}

int dp[1001][1001];
int memo(vector<int>& a, int i, int j)
{
    if(i >= j)
        return 0;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for(int k = i ; k <= j - 1 ; k++)
    {
        int temp = memo(a,i,k) + memo(a,k+1,j) + a[i-1] * a[k] * a[j];
        ans = min(ans,temp); 
    }
    return dp[i][j] = ans;
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i< n ; i++) 
        cin >> arr[i];
    memset(dp,-1,sizeof(dp));
    cout << MCM(arr,1,n-1) << endl;
    cout << memo(arr,1,n-1) << endl;
}