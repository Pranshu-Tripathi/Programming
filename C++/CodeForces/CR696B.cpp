#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

bool isPrime[100006];

void _run()
{

    int d;
    cin >> d;

    vector<int> ans;
    ans.push_back(1);
    int i;
    for( i = d + 1 ; i <= 100005 ; i++)
    {
        if(isPrime[i])
        {
            ans.push_back(i);
            break;
        }
    }

    for(int j = d + i ; j <= 1000005 ; j++)
    {
        if(isPrime[j])
        {
            ans.push_back(j);
            break;
        }
    }

    ll prod = 1;
    for(auto x : ans)
    {
        // cout << x << ' ';
        
        prod *= x;
    }
    
    cout << prod << endl;

}

int main()
{
    
    fast;

    isPrime[0] = isPrime[1] =false;

    for(int i = 2 ; i <= 100005 ; i++)
        isPrime[i] = true;

    for(int i = 2 ; i*i <= 100005 ; i++)
    {
        if(isPrime[i])
        {
            for(int j = i * i ; j <= 100005 ; j+=i)
                isPrime[j] = false;
        }
    }

    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
