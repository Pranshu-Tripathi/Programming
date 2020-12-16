#include<bits/stdc++.h>
using namespace std;


void run_testcase()
{
    int x;
    cin >> x;
    vector<int> num;
    if(x  < 10)
    {
        cout << x << endl;
        return;
    }

    if(x > 45)
    {
        cout << -1 << endl;
        return;
    }

    int digit = 9;

    while(x)
    {
        if(x < digit)
        {
            digit --;
            continue;
        }
        x -= digit;
        num.push_back(digit);
        digit--;
    }

    for(int i = num.size() - 1 ; i >= 0; i--)
    {
        cout << num[i]  ;
    }

    cout << endl;
    return;
}

int main()
{
    int test;
    cin>> test;
    while(test--)
        run_testcase();
    return 0;
}