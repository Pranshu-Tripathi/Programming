#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; ++i)
    {
        cin >>a[i];
    }
    int mi = *min_element(a.begin(),a.end());
    int mx = *max_element(a.begin(),a.end());
    int minPos,maxPos;
    for(int i = n ; i >= 0 ; --i)
    {
        if(a[i] == mi)
        {
            minPos = i;
            break;
        }
    }
    int tim = 0;
    tim+= n - minPos;
    for(int i = minPos ; i < n - 1 ; i++)
    {
        swap(a[i],a[i+1]);
    }

    for(int i = 0 ; i < n ;i ++)
    {
        if(a[i] == mx)
        {
            maxPos = i;
            break;
        }
    }
    
    tim += maxPos - 1;
    cout << tim << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
