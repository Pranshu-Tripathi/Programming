/*
Subset Sum Problem (If there exists a subset with sum equal to given sum)
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n,sum;
    cin >> n >> sum;
    vector<int> arr(n);
    for(int i = 0; i < n ; i++)
    {
        cin >> arr[i];
    }

    vector<vector<bool>> dp(n,vector<bool>(sum+1,false));

    for(int i = 0 ; i < n;i ++)
    {
        for(int j = 0 ;  j <= sum ; j++)
        {
            if(j == 0)
            {
                dp[i][j] = true;
            }
            if(i == 0 && j != 0)
            {
                if(arr[i] == j)
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        }
    }



    for(int i = 1 ; i < n ; i++)
    {
        for(int j = 1 ; j <= sum ; j++)
        {
            bool opt1 = dp[i-1][j];
            bool opt2 = (j >= arr[i]) ? dp[i-1][j-arr[i]] : false;
            dp[i][j] = opt1 || opt2;
        }
    }
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j <= sum ; j ++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
