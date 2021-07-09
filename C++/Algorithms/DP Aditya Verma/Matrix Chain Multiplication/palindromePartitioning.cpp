#include<bits/stdc++.h>
using namespace std;

bool isPal(string s,int i, int j)
{
    while(i <= j)
    {
        if(s[i] != s[j])
            return false;
        i++,j--;
    }
    return true;
}

int parts(string s, int i, int j)
{
    if(i >= j)
        return 0;
    if(isPal(s,i,j))
        return 0;
    
    int ans = INT_MAX;
    for(int k = i ; k < j ; k++)
    {
        int temp = parts(s,i,k) + parts(s,k+1,j) + 1;
        ans = min(ans,temp);
    }
    return ans;
}

int dp[1001][1001];
int memo(string s, int i, int j)
{
    if(i >= j)
        return 0;
    if(isPal(s,i,j))
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int ans = INT_MAX;
    for(int k = i ;  k < j ;k ++)
    {
        int left,right;
        if(dp[i][k] != -1)
            left = dp[i][k];
        else
            left = dp[i][k] = memo(s,i,k);
        if(dp[k+1][j] != -1)
            right = dp[k+1][j];
        else
            right = dp[k+1][j] = memo(s,k+1,j);
        int temp = left + right + 1;
        ans = min(temp,ans);
    }
    return dp[i][j] = ans;
}

int main()
{
    string s;
    cin >> s;
    cout << parts(s,0,s.length()-1) << endl;
    memset(dp,-1,sizeof(dp));
    cout << memo(s,0,s.length()-1) << endl;
}