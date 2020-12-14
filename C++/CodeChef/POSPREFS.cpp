/*

You are given two positive integers N and K, where K≤N. Find a sequence A1,A2,…,AN such that:
for each valid i, Ai is either i or −i
there are exactly K values of i such that 1≤i≤N and A1+A2+…+Ai>0
If there are multiple solutions, you may print any one of them. It can be proved that at least one solution always exists.

*/

#include<bits/stdc++.h>
using namespace std;

void run_testcase()
{
    int n,k;
    cin >> n >> k;
    vector<int> pattern(n+1,0);
    int i = 1;
    while(k && i <= n)
    {
        pattern[i] = i;
        i += 2;
        k--;
    }   
    i = n - n % 2;
    while(k)
    {
        pattern[i] = i;
        i -=2;
        k--;
    }
    for(int i = 1; i <=n ; i++)
    {
        if(pattern[i])
        {
            cout << pattern[i] <<" ";
        }
        else cout << -i << " ";
    }

    cout << endl;
    return ;
}


int main()
{
    int test;
    cin >> test;
    while(test--)
        run_testcase();
    return 0;
}