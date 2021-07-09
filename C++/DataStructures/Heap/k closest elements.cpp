#include <bits/stdc++.h>
using namespace std;

void displayKClosestToX(vector<int> &v, int x, int k)
{
    priority_queue<pair<int, int>> max_heap;
    for (int &z : v)
    {
        max_heap.push({abs(x - z), z});
        if (max_heap.size() > k)
            max_heap.pop();
    }
    while (max_heap.size())
    {
        cout << max_heap.top().second << ' ';
        max_heap.pop();
    }
}

int main()
{
    int n, x, k;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cin >> x >> k;
    displayKClosestToX(v, x, k);
}