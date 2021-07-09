#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int optimalEarning(vector<int>& a, int i, int j)
{   
    if(i == j)
        return a[i];
    if(i == j - 1)
        return max(a[i],a[j]);
    
    if(dp[i][j] != -1)
        return dp[i][j];
    int op1 = a[i] + min(optimalEarning(a,i+2,j),optimalEarning(a,i+1,j-1));
    int op2 = a[j] + min(optimalEarning(a,i+1,j-1),optimalEarning(a,i,j-2));
    return dp[i][j] = max(op1,op2);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i= 0 ;  i < n ; i++)
        cin >> a[i];
    memset(dp,-1,sizeof(dp));
    cout << optimalEarning(a,0,n-1);
}