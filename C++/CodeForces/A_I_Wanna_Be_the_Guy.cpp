#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

const string yes = "I become the guy.";
const string no = "Oh, my keyboard!";

void _run()
{
    int n;
    cin >> n;
    int lx;
    cin >> lx;
    set<int> levels;
    for(int i = 0 ; i < lx ; i++)
    {
        int y;
        cin >> y;
        levels.insert(y);
    }
    int ly;
    cin >> ly;
    for(int i = 0 ; i < ly ; i++)
    {
        int x;
        cin >> x;
        levels.insert(x);
    }

    if(levels.size() == n)
    {
        cout << yes << endl;
    }
    else
    {
        cout << no << endl;
    }
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
