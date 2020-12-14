/*
You are given two positive integers A and B.
Find the number of pairs of positive integers (X,Y) such that 1≤X≤A, 1≤Y≤B and X+Y is even.
*/

#include<bits/stdc++.h>
using namespace std;

void run_testcase()
{
    long long A,B;
    cin >> A >> B;
    if(A < 2 && B < 2)
    {
        cout << 1 << endl;
        return;
    }
    long long xEven = A/2;
    long long xOdd = A - A/2;
    long long yEven = B/2;
    long long yOdd = B - B/2;
    long long EvenSum = xEven * yEven;
    long long OddSum = xOdd * yOdd;
    cout << EvenSum + OddSum << endl;
    return;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
        run_testcase();
    return 0;
}