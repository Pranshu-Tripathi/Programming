#include<bits/stdc++.h>
using namespace std;

string no = "NO";
string yes = "YES";
void _run()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    int one =0;
    int sum= 0;
    for(int i = 0 ;  i < n ; i++)
    {
        cin >> arr[i];
        if(arr[i] == 1)
            one++;
        sum += arr[i];
    }

    if(sum % 2 != 0)
    {
        cout << no << endl;
        return;
    }

    int two = n - one;

    sum = sum / 2;

    int required = sum / 2;

    if(two >= required)
    {
        sum -= required * 2;
    }

    else
    {
        sum -= two * 2;
    }
    
    if(one >= sum)
    {
        cout << yes << endl;
    }
    else
    {
        cout << no << endl;
    }
    
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int test;
    cin >> test;
    while(test--)
        _run();
    
    return 0;
}