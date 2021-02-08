#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

const string first = "Akshat";
const string second = "Malvika";

void _run()
{
    int n,m;
    cin >> n >> m;
    int moves = min(n,m);
    if(moves % 2 == 0)
        cout << second << endl;
    else
        cout << first << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
