#include<bits/stdc++.h>
using namespace std;

int bs(int key, int low, int high, vector<int>& arr)
{
    int maxLimit = high;
    while(low<high) {
    int mid = low +(high-low)/2;
    if(arr[mid]<key) {
    low = mid + 1;
    }
    else high = mid;
    }
    return high == maxLimit ? -1 : high;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x;
        cin >> x;
        cout << bs(x,0,n-1,arr) << endl;
    }
    
}