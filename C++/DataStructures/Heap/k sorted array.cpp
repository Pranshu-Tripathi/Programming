#include<bits/stdc++.h>
using namespace std;

void sortedArray(vector<int>&v , int k)
{
    priority_queue<int,vector<int>,greater<int>> min_heap;
    for(int &x : v)
    {
        min_heap.push(x);
        if(min_heap.size() > k)
        {
            cout << min_heap.top() << ' ';
            min_heap.pop();
        }
    }
    while(min_heap.size())
    {
        cout << min_heap.top() << ' ';
        min_heap.pop();
    }
}

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> v(n);
    for(size_t i =  0 ; i < n ;  i++)
        cin >> v[i];
    sortedArray(v,k);
}