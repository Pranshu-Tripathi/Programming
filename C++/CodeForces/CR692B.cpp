#include<bits/stdc++.h>
using namespace std;

void getDigits(long long  n, vector<int> & digits)
{
    while(n)
    {
        if(n%10 != 0)
            digits.push_back(n%10);
        n /= 10;
    }
}

void _run()
{
    long long n;
    cin >> n;
    vector<int> digits;
    
    
    for(long long i = n ; i <= 1000000000000000005 ; i++)
    {
        digits.clear();
        getDigits(i,digits);
        bool flag = true;
        for(int x : digits)
        {
            if( i % x != 0)
            {
                flag = false;
                break;
            }
        }   
        if(flag)
        {
            cout << i << endl;
            break;
        }
    }

   return;
}

int main()
{
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}