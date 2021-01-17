#include<bits/stdc++.h>
using namespace std;
#define ll long long

const string pat = "abcd";

void _run()
{
    int n;
    cin >> n;

    int x = n / 4;
    int y = n % 4;
    string ans = "";
    for(int i = 0 ; i < x ; i++)
        ans += pat;
    for(int i = 0 ; i < y ; i++)
        ans += pat[i];
    
    cout << ans << endl;

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;
    while(test--)
        _run();
    return 0;
}