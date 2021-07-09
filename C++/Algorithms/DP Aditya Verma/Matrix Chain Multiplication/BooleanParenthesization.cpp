#include<bits/stdc++.h>
using namespace std;

int bp(string s, int i, int j, int isbool)
{
    if(i > j)
        return 0;
    
    if(i == j)
    {
        if(isbool)
            return s[i] == 'T';
        else
            return s[i] == 'F';
    }
    int ans = 0;
    for(int k = i + 1 ; k < j ; k+=2)
    {
        int lt = bp(s,i,k-1,true);
        int lf = bp(s,i,k-1,false);
        int rt = bp(s,k+1,j,true);
        int rf = bp(s,k+1,j,false);
        if(s[k] == '&')
        {
            if(isbool)
                ans += lt * rt;
            else
                ans += lf*rt + lt*rf + lf*rf;
        }
        else if(s[k] == '|')
        {
            if(isbool)
                ans += lt * rf + lf * rt + lt * rt;
            else
                ans += lf * rf;
        }
        else 
        {
            if(isbool)
                ans += lt * rf + lf * rt;
            else
                ans += lt * rt + lf * rf;
        }
    }

    return ans;
}


int dp[1001][1001][2];
int memo(string s, int i, int j, int tbool)
{
    if(i > j)
        return 0;
    
    if(i == j)
    {
        if(tbool)
            return dp[i][j][1] = (s[i] == 'T');
        else
            return dp[i][j][0] = (s[i] == 'F');
    }

    if(dp[i][j][(int)tbool] != -1)
        return dp[i][j][(int)tbool];
    
    int ans = 0;
    for(int k = i + 1 ; k < j ; k+=2)
    {
        int lt = bp(s,i,k-1,true);
        int lf = bp(s,i,k-1,false);
        int rt = bp(s,k+1,j,true);
        int rf = bp(s,k+1,j,false);
        if(s[k] == '&')
        {
            if(tbool)
                ans += lt * rt;
            else
                ans += lf*rt + lt*rf + lf*rf;
        }
        else if(s[k] == '|')
        {
            if(tbool)
                ans += lt * rf + lf * rt + lt * rt;
            else
                ans += lf * rf;
        }
        else 
        {
            if(tbool)
                ans += lt * rf + lf * rt;
            else
                ans += lt * rt + lf * rf;
        }
    }

    return dp[i][j][(int)tbool] = ans;
}

int main()
{
    string s;
    cin >> s;
    cout << bp(s,0,s.length()-1,true) << endl;
    memset(dp,-1,sizeof(dp));
    cout << memo(s,0,s.length()-1,true);
}