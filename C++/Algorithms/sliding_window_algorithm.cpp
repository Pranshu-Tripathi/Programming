/*
Sliding window algorithm is useful to calculate some computaion of fixed K length.
For Example given an array a, compute the maximum sum of k consecutive elements.
*/

#include<bits/stdc++.h>
using namespace std;

void slide_the_window(int n, int k, vector<int>& a)
{
    long long max_sum = 0;
    for(int i = 0 ; i < k ; i++)
        max_sum += a[i];
    long long window_sum = max_sum;
    for(int i = k ; i < n ; i++)
    {
        window_sum += a[i] - a[i-k];
        max_sum = max(max_sum,window_sum);
    }

    cout << max_sum << endl;
}


int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a;
    int x;
    for(int i = 0 ; i < n ; i++)
        cin >> x, a.push_back(x);

    slide_the_window(n,k,a);
}