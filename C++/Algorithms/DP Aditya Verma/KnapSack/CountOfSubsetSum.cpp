#include <bits/stdc++.h>
using namespace std;

int _reccur(vector<int> &a, int ts, int n)
{
    if (ts == 0)
        return 1;
    if (n == 0)
        return 0;

    if (a[n - 1] > ts)
        return _reccur(a, ts, n - 1);

    int op1 = _reccur(a, ts, n - 1);
    int op2 = _reccur(a, ts - a[n - 1], n - 1);
    return op1 + op2;
}

int dp[1003][1003];
int memoiz(vector<int> &a, int ts, int n)
{
    if (ts == 0)
        return 1;
    if (n == 0)
        return 0;
    if (dp[n][ts] != -1)
        return dp[n][ts];
    if (a[n - 1] > ts)
        return dp[n][ts] = memoiz(a, ts, n - 1);
    int op1 = memoiz(a, ts, n - 1);
    int op2 = memoiz(a, ts - a[n - 1], n - 1);
    return dp[n][ts] = op1 + op2;
}

int iterative(vector<int> &a, int ts, int n)
{
    int dpi[n + 1][ts + 1];
    memset(dpi, 0, sizeof(dpi));
    for (int i = 0; i <= n; i++)
        dpi[i][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= ts; j++)
        {
            dpi[i][j] = dpi[i - 1][j];
            if (a[i - 1] <= j)
                dpi[i][j] += dpi[i - 1][j - a[i - 1]];
        }
    }
    return dpi[n][ts];
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int sum;
    cin >> sum;
    memset(dp, -1, sizeof(dp));
    cout << "Recur : ";
    cout << _reccur(arr, sum, n) << endl;
    cout << "Memoiz : ";
    cout << memoiz(arr, sum, n) << endl;
    cout << "Iterative : ";
    cout << iterative(arr, sum, n) << endl;
}