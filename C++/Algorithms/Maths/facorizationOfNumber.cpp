/*
Sieve of Eratosthenes for fast factorization
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> factorization(int n)
{
    vector<int> res;
    for(int i = 2 ; i * i <= n ; i++)
    {
        while(n % i == 0)
        {
            res.push_back(i);
            n/=i;
        }
    }
    if(n != 1)
        res.push_back(n);
    return res;
}