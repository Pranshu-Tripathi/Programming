#include<bits/stdc++.h>
using namespace std;

#define ll long long

void factorization(set<int>& factors, int n)
{
    for(int i = 2 ; i * i <= n ; i++)
    {
        while(n % i == 0)
        {
            factors.insert(i), n /=i;
        }
    }
    if(n != 1)
        factors.insert(n);

}

void _run()
{
    int n;
    cin >> n;

    set<int> factors;
    factors.insert(n);
    factorization(factors,n);
    vector<int> ans;
    ans.push_back(n);
    while(n > 1)
    {
        for(auto x : factors)
        {
            if(n % x == 0)
            {
                ans.push_back(n/x);
                n /= x;
                break;
            }
        }
    }


    // sort(ans.begin(),ans.end(),greater<int>());
    for(int i : ans)
        cout << i << ' ';
    cout << endl;
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