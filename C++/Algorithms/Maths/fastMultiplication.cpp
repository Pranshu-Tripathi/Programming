#include<bits/stdc++.h>
using namespace std;

int mul(int a,int b)
{
    if(b==0)
        return 0;
    if(b == 1)
        return a;
    int r = mul(a,b/2);
    if(b%2 == 0)
        return r +r ;
    else 
        return r +r +a;
}

int main()
{
    cout << mul(2,3);
     cout << endl << mul(16,3);
}