#include<bits/stdc++.h>
using namespace std;

void run_testcase()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }

    int start = 0 ,end = n -1;

    bool swit = true;
    while(start <= end)
    {
        if(swit)
        {
            cout << arr[start]  << " ";
            start++;
            swit = false;
        }
        else
        {
            cout << arr[end] << " ";
            end--;
            swit = true;
        }   
    }
    cout << endl;
    return;

}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int test;
    cin >> test;
    while(test--)
        run_testcase();
    return 0;
}