#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum =0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a.begin(),a.end(),greater<int>());
    int count = 0;
    sum /= 2;
    for(int i = 0 ; i < n ; i++)
    {
        sum -= a[i];
        count++;
        if(sum < 0)
            break;
    }
    cout << count << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    while(test--)
        _run();
    return 0;
}
