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

#define mod 1000000007

int main()
{
    int i,j,n;
    cin >> n;
    vector<string> s(n);

    FOR(i,0,n)
    {
        cin >> s[i];
    }

    int dp[n][n];
    dp[0][0] = 1;

    for(int i = 0 ; i < n; i ++){
        for(int j = 0 ; j < n ; j++){
            if(s[i][j] == '*'){
                dp[i][j] = 0;
                continue;
            }
            else if(i==0 && j ==0){
                continue;
            }
            else if(i == 0){
                dp[i][j] = dp[i][j-1];
            }else if(j == 0){
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = (dp[i-1][j] % mod + dp[i][j-1] % mod)%mod; 
            }
        }
    }
    cout << dp[n-1][n-1];
}