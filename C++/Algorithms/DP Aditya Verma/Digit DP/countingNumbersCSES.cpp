#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define vi vector<int>
#define vll vector<long long int>
#define vvi vector<vector<int>>
#define all(arr) arr.begin(), arr.end()
#define pii pair<int, int>
#define mod (ll)1000000007
#define debug(x) cout << #x << " " << x << endl;
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define file                          \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout)
using namespace std;
#define N 100001
void debugv(vll &arr, int n)
{
    cout << "arr [ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "]\n";
}
void debuga(ll arr[], int n)
{
    cout << "arr [ ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "]\n";
}

ll dp[20][11][2][2];
ll solve(string &num, int ind, int x, bool leadingzeros, bool tight)
{
    if (ind == num.size())
        return 1;
    if (dp[ind][x][leadingzeros][tight] != -1)
        return dp[ind][x][leadingzeros][tight];
    int ub = tight ? (num[ind] - '0') : 9;
    ll sum = 0;
    for (int i = 0; i <= ub; i++)
    {
        if (i == x && !leadingzeros)
            continue;
        sum = sum + solve(num, ind + 1, i, leadingzeros & (i == 0), tight & (i == ub));
    }
    return dp[ind][x][leadingzeros][tight] = sum;
}
void solve1()
{
    ll l, r;
    cin >> l >> r;
    if (l == 0 && r == 0)
    {
        cout << 1 << endl;
        return;
    }
    l--;
    string L = to_string(l);
    string R = to_string(r);
    memset(dp, -1, sizeof dp);
    ll left = solve(L, 0, 10, true, true);
    memset(dp, -1, sizeof dp);
    ll right = solve(R, 0, 10, true, true);
    cout << right - left << endl;
}
int main()
{
    fast;
    int t = 1;
    //cin>>t;
    while (t--)
        solve1();
}