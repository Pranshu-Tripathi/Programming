/*
Given an array of size n. 
Find the xor of all the pairwise sum possible
Basic Approach - > o(n^2)
Algo used : - only the diagonal elements xor is needed in final answer o(n);
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
    int i,n;
    cin >> n;
    int arr[n];
    int xoe = 0;
    FOR(i,0,n)
    {
        cin >> arr[i];
        xoe ^= (2 * arr[i]); 
    }
    cout << xoe  << endl;
}