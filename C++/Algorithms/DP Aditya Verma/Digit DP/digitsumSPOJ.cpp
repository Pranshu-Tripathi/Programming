#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define vi vector<int>
#define vll vector<long long int>
#define vvi vector<vector<int>>
#define all(arr) arr.begin(), arr.end()
#define pii pair<int, int>
#define mod (ll)1000000007
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define file                          \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
using namespace std;
#define N 100001

ll dp[16][2];
ll C(string &num, int ind, bool tight)
{
    if (ind == num.length())
        return 1;
    if (!tight)
    {
        return (ll)(pow(10, num.length() - ind) + 0.1);
    }
    else
        return stoll(num.substr(ind, num.length() - ind)) + 1;
}
ll solve(string &num, int ind, bool tight)
{
    if (ind == num.length())
        return 0;
    if (dp[ind][tight] != -1)
        return dp[ind][tight];
    int ub = (tight) ? (num[ind] - '0') : 9;
    ll sum = 0;
    for (int i = 0; i <= ub; i++)
    {
        sum = sum + (i * C(num, ind + 1, tight & (i == ub)) + solve(num, ind + 1, tight & (i == ub)));
    }
    return dp[ind][tight] = sum;
}

void solve1()
{
    ll l, r;
    cin >> l >> r;
    if (l != 0)
        l--;

    string L = to_string(l);

    string R = to_string(r);
    memset(dp, -1, sizeof dp);
    ll high = solve(R, 0, true);
    memset(dp, -1, sizeof dp);
    ll low = solve(L, 0, true);
    cout << high - low << endl;
}
int main()
{
    fast;
    int t = 1;
    cin >> t;
    while (t--)
        solve1();
}