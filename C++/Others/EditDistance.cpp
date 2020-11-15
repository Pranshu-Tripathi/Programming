/*

The edit distance between two strings is the minimum number of operations required to transform one string into the other.

The allowed operations are:
-Add one character to the string.
-Remove one character from the string.
-Replace one character in the string.
For example, the edit distance between LOVE and MOVIE is 2, because you can first replace L with M, and then add I.

Your task is to calculate the edit distance between two strings.


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

int main()
{
    string s,t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();

    int dp[n+1][m+1];

    memset(dp,1000005,sizeof(dp));
    dp[0][0] = 0;
    int i,j;

    FORE(i,0,n)
    {
        FORE(j,0,m)
        {
            if(i)   dp[i][j] = min(dp[i][j],dp[i-1][j] + 1);
            if(j)   dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
            if(i && j)  dp[i][j] = min(dp[i][j] , dp[i-1][j-1] + (s[i-1] != t[j-1])); 
        }
    }

    cout << dp[n][m];
}