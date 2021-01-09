#include<bits/stdc++.h>
using namespace std;
#define ll long long



void _run()
{
    int n;
        cin>>n;
        if(n == 1)
        {
            cout<<"9\n";
            return;
        }
        int a[n];
        int num = 9;
        a[1] = 8;
        a[0] = 9;
        for(int i = 2 ; i < n ; i++)
        {
            a[i] = num;
            num++;
            if(num == 10)
            {
                num = 0;
            }
        }
        for(int i = 0 ; i < n ; i++)
        {
            cout<<a[i];
        }
        cout << endl;
        return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
