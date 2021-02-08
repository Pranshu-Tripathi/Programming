/*

using sieve of erethrones


*/

#include<bits/stdc++.h>
using namespace std;

bool isPrime[100005];

int main()
{
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1] = false;
    isPrime[2] = false;

    for(int i = 2 ; i * i <= 100005 ; i++)
    {
        for(int j = i * i; j <= 100005 ; j += i)
        {
            isPrime[j] = false;
        }
    }

    cout << isPrime[5] << endl;
    cout << isPrime[31] << endl;
    cout << isPrime[73] << endl;
}