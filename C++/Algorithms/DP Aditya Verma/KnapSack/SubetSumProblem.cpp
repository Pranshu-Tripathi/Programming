/*
Subset Sum Problem (If there exists a subset with sum equal to given sum)
*/

#include<bits/stdc++.h>
using namespace std;

bool _reccur(vector<int>& arr, int targetSum,int n)
{
    if(targetSum == 0)
        return true;
    
    if(n == 0)
        return false;
    
    if(targetSum < arr[n-1])
        return _reccur(arr,targetSum,n-1);
    
    bool op1 = _reccur(arr,targetSum,n-1);
    bool op2 = _reccur(arr,targetSum-arr[n-1],n-1);
    return op1 || op2;
}

int dp[1003][1003];
bool memoization(vector<int>& arr, int t, int n)
{
    memset(dp,-1,sizeof(dp));
    if(t == 0)
        return true;
    
    if(n == 0)
        return false;
    
    if(dp[n][t] != -1)
        return dp[n][t];

    bool op1 = memoization(arr,t-arr[n-1],n-1);
    bool op2 = memoization(arr,t,n-1);
    return dp[n][t] = op1 || op2;
}


bool iterative(vector<int>& arr, int t, int n)
{
    bool dpi[n+1][t+1];
    memset(dpi,false,sizeof(dpi));
    for(int i = 0 ; i <= t ; i++)
        dpi[0][i] = false;
    for(int i = 0 ; i <= n ; i++)
        dpi[i][0] = true;

    for(int i = 1;  i <= n ; i++)
    {
        for(int j = 1 ; j <= t ; j++)
        {
            dpi[i][j] = dpi[i-1][j] || dpi[i][j];
            if(arr[i-1] <= j)
                dpi[i][j] = dpi[i-1][j-arr[i-1]] || dpi[i][j];
        }
    }

    return dpi[n][t];
}

int main()
{
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int i = 0 ; i < n ; i++)
        cin >> ar[i];
    int sum;
    cin >> sum;
    cout << "Recur : ";
    cout << _reccur(ar,sum,n) << endl;
    cout << "Memoiz : ";
    cout << memoization(ar,sum,n) << endl;
    cout << "Iterative : ";
    cout << iterative(ar,sum,n) << endl;
}