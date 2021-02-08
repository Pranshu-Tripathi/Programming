#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n;
    cin >> n;
    vector<int> str(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> str[i];
    }

    sort(str.begin(),str.end());
    
    for(int piles = 1 ; piles <= n ; piles++)
    {
        bool smallest = true;
        for(int i = 0 ; i < n ; i ++)
        {
            if(str[i] < i/piles)
            {
                smallest = false;
                break;
            }
        }
        if(smallest)
        {
            cout << piles << endl;
            break;
        }
            
    }
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
