#include<bits/stdc++.h>
using namespace std;

void run_testcase()
{

    int n,k;
    cin >> n >> k;

    string pat;
    string z = "cba";

    for(int i = 0 ; i < k ; i++)
    {
        pat.push_back('a');
    }

    int c = n - k;
    for(int i = 0 ; i < c ; i++)
    {
        pat.push_back(z[i % 3]);
    }
    
    for(int i = 0 ; i < n ; i++)
    {
        cout << pat[i] ;
    }

    cout << endl;

}


int main()
{
    int test;
    cin >> test;
    while(test--)
        run_testcase();
    
    return 0;
}