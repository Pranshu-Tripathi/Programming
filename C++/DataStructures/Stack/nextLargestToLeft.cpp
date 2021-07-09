#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i  < n ; i++)
        cin >> arr[i];
    int ans[n];
    ans[0] = -1;
    stack<int> s;
    s.push(arr[0]);
    for(int i =  1 ; i < n ; i++)
    {
        if(s.empty())
            ans[i] = -1;
        else if(s.top() > arr[i])
            ans[i] = s.top();
        else if(s.top() <= arr[i])
        {
            while(!s.empty() and s.top() <= arr[i])
                s.pop();
            if(s.empty())
                ans[i]  = -1;
            else
                ans[i] = s.top();
        }
        s.push(arr[i]);
    }
    for(int i = 0 ; i < n ; i++)
        cout << ans[i] << ' ';
}