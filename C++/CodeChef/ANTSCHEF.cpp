#include<bits/stdc++.h>
using namespace std;

void deb()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        int m;
        cin >> m;
        long long cnt1 = 0,cnt2 = 0,x;
        for(int i = 0 ; i < m ; i++)
        {
            cin >> x;
            if(x < 0)
                cnt1++;
            else
                cnt2++;
        }
        cout << cnt1 * cnt2 << endl;
    }
    else
    {
        return;
    }
    
}


int main()
{
    int test;
    cin >> test;
    while(test--)
        deb();
    return 0;
}