#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    vector<int> ans;
    stack<int> s;
    ans.push_back(-1);
    s.push(arr.back());
    for(int  i = n - 2 ; i >= 0 ; i--)
    {
        if(s.empty())
            ans.push_back(-1);
        if(s.top() > arr[i])
            ans.push_back(s.top());
        if(s.top() <= arr[i])
        {
            while(!s.empty() && s.top() <= arr[i])
                s.pop();
            if(s.empty())
                ans.push_back(-1);
            else
                ans.push_back(s.top());
        }
        s.push(arr[i]);
    }
    reverse(ans.begin(),ans.end());
    for(int i = 0 ;i < ans.size() ; i++)
        cout << ans[i] << ' ';
}