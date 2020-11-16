/*
Properties of XOR
    1. Different bits give result 1
    2. A ^ A = 0
    3. A ^ 0 = A
    4. XOR is associative.
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

int main()
{
    int n;
    cin >> n;
    int temp = n^0;
    cout << temp << endl;
    temp = n^n;
    cout << temp << endl;
    temp = (n^(n-1) )^(n-2);
    cout << temp << endl;
    temp = (n^(n-2))^(n-1);
    cout << temp << endl;
}