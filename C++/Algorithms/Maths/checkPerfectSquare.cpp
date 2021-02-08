#include<bits/stdc++.h>
using namespace std;


bool isPerfectSquare(long double x)
{
    if (x >= 0) {
 
        long double sr = sqrt(x);
         
        return (sr * sr == x);
    }
    return false;
}