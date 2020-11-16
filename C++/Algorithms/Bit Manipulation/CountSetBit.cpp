/*

Taking && of n-1 and n makes one set bit of n zero

*/
#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0) , cin.tie(0),cout.tie(0);
#define LOG(X)      cout << x << endl;
#define ll long long
#define endl "\n"
#define And &&
#define Or ||
#define FOR(i,a,b)              for(int i = a; i < b; i++)
#define REV(i,a,b)              for(int i = a; i >= b; i--)
#define FORE(i,a,b)             for(int i = a; i <= b; i++)
#define pii                     pair<int,int>
#define pll                     pair< long long int, long long int> 
typedef 						long double ld;
typedef 						unsigned long long ull;
#define F                       first
#define S                       second
#define pb                      push_back

void testcase()
{
    ll n;
    cin >> n;
    ll temp = n;
    int setBit = 0;
    while(temp != 0)
    {
        setBit++;
        temp = (temp & (temp - 1));
    }
    cout << setBit << endl;
    return;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        testcase();
    }
    
}