/*
Given an sequence output 
(A1 ^ A2) + (A1 ^ A3) + ................. + (A1 ^ An) +
                  (A2 ^ A3) + ................. + (A2 ^ An)+
                  .
                  .
                  .
                                                       (An-1 ^ An)

    Algorithm :-
        We calculate the elements that have set bit at ith position. If x have set y have unset,
        then the coiefficient would be xy times the ith power of 2.

        example 5 - > 101
                      3 - > 011
                      9 -> 1001
        (5 ^3) + (5 ^ 9) + (3 ^ 9) = 28 = 2 * 2 ^ 3 + 2 * 2^2 +2 * 2^1 + 0 * 2 ^ 0
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
    int i,h,n;
    cin >> n;
    int arr[10001];
    FOR(i,0,n)
    {
        cin >> arr[i];
    }

    int res = 0;

    FOR(i,0,31)
    {
        int zero_bit = 0;
        int one_bit = 0;
        int p = 1;
        FOR(h,0,n)
        {
            

            if((arr[h] &  (1 << i)) != 0)   one_bit++;
            else                                   zero_bit++;
        }
        p *= (zero_bit * one_bit);

        res += p * (1 << i);
    }
    cout << res << endl;
}