#include <bits/stdc++.h>
using namespace std;

string solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int lt = 2*n-1;
    string ans = "";
    for(int i = 0 ; i < lt ; i +=2){
        ans+=s[i];
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        cout <<  solve() << endl;
}