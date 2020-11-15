/*
Find All possible combinatoins with given dinominations to make sum x
*/

#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0) , cin.tie(0),cout.tie(0);
#define LOG(X)      cout << x << endl;
#define ll long long
#define endl "\n"
#define And &&
#define Or ||
#define FOR(i,a,b)              for(int i = a; i < b; i++)
#define REV(i,a,b)              for(int i = a; i >= b; i--)
#define FORE(i,a,b)             for(int i = a; i <= b; i++)
#define pii                     pair<int,int>
#define pll                     pair< long long int, long long int> 
typedef 						long double ld;
typedef 						unsigned long long ull;
#define F                       first
#define S                       second
#define pb                      push_back

#define m 1000000007


int main()
{
    int i=0,j=0,n,x;
    cin >> n >> x;
    try
    {
        int  dp[n+1][x+1];
        int coins[n+1];coins[0] = 0;
        FORE(i,1,n)
        {
            cin >> coins[i];
        }

        FORE(i,1,n)
        {
            FORE(j,0,x)
            {
                if(j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int op1 = (j < coins[i]) ? 0 : (dp[i][j - coins[i]]);
                    int op2 = (i-1 == 0) ? 0 : dp[i-1][j];
                    dp[i][j] =(op1 + op2) % m;
                }
                
            }
        }
        cout << dp[n][x] << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        cout << e.what() << endl;
    }
    

   
   
}

