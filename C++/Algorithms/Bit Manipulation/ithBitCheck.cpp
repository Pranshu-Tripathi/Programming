/*
Checking wether the Ith bit of a number is set or not. Left shift and "And" operation.
*/

#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0) , cin.tie(0),cout.tie(0)
#define LOG(X)      cout << x << endl
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

int main()
{
    fast;
    int ques,n,i;
    cin >> ques;
    while(ques--)
    {
        cin >> n >> i;
        bool x;
        int f = 1;
        f = (f << i);
        int test = n & f;
        if(test == 0)   cout << false << endl;
        else         cout << true << endl;
    }
}