#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    
    int left[n],right[n];
    stack<pair<int,int>> s;
    s.push({arr[0],0});
    left[0] = -1;
    for(int i = 1 ; i < n ; i++)
    {
        if(s.empty())
            left[i] = -1;
        if(s.top().first < arr[i])
            left[i] = s.top().second;
        if(s.top().first >= arr[i])
        {
            while(!s.empty() and s.top().first >= arr[i])
                s.pop();
            if(s.empty())
                left[i] = -1;
            else
                left[i] = s.top().second;
        }
        s.push({arr[i],i});
    }
    cout << "left :";
    for(int i = 0 ; i < n; i ++)
        cout << left[i] << ' ';
    cout << endl;
    right[n-1] = n ;
    while(!s.empty())
        s.pop();
    s.push({arr[n-1],n-1});
    for(int i = n - 2 ; i >= 0 ; i--)
    {
        if(s.empty())
            right[i] = n ;
        if(s.top().first < arr[i])
            right[i] = s.top().second;
        if(s.top().first >= arr[i])
        {
            while(!s.empty() and s.top().first >= arr[i])
                s.pop();
            if(s.empty())
                right[i] = n;
            else
                right[i] = s.top().second;
        }
        s.push({arr[i],i});
    }
    cout << "right :";
    for(int i = 0 ; i < n ; i++)
        cout << right[i] << ' ';
    cout << endl;
    int area = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int len = right[i] - left[i] - 1;
        int a = len * arr[i];
        area = max(area,a);
    }
    cout << area << endl;
}