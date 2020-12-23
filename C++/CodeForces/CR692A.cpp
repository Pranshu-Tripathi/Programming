#include<bits/stdc++.h>
using namespace std;
string yes = "Yes";
string no = "No";

void run_testcase()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int bcnt = 0;
    for(int i = n -1 ; i >= 0 ; i--)
    {
        if(s[i] != ')')
            break;
        bcnt++;
    }

    (bcnt > n / 2) ? cout << yes << endl : cout << no << endl;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);

    int test;
    cin>> test;
    while(test--)
        run_testcase();
    return 0;
}