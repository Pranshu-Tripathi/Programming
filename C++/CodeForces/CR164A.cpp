#include<bits/stdc++.h>
using namespace std;

int freq[101];

void _run()
{
    int n;
    cin >> n;
    int h[n], a[n];
    for(int i = 0 ; i < n ; i++)
        cin >> h[i] >> a[i] , freq[a[i]]++;
    
    int ga = 0;
    for(int i = 0 ; i < n ; i ++)
        ga += freq[h[i]];
    
    cout << ga << endl;
}

int main()
{
    int test = 1;
    while(test--)
        _run();
    return 0;
}