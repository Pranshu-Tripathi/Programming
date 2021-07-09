#include <bits/stdc++.h>
using namespace std;

int kLargestElement(vector<int> &v, int k)
{
    priority_queue<int> max_heap;
    for (int &x : v)
    {
        max_heap.push(x);
        if (max_heap.size() > k)
            max_heap.pop();
    }
    return max_heap.top();
}

int main()
{
    int n, k;
    cin >> n >> k;
    std::vector<int> v(n);
    for (size_t i = 0; i < n; i++)
        cin >> v[i];

    cout << kLargestElement(v, k) << endl;
}