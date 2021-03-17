#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000009

vector<vector<int>> ids(27);


int _getNum(char a)
{
    return a - 'a' + 1;
}

void _run()
{    
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >>t;
    vector<int> minPos(m,0);
    vector<int> maxPos(m,0);
    int j = 0;
    for(int i = 0 ;i < n ;i++)
    {
        if(j < m && s[i] == t[j])
        {
            minPos[j] = i;
            j++;   
        }
    }
    int h = m -1;
    for(int i = n - 1 ; i >=0 ; i--)
    {
        if(h >= 0 && s[i] == t[h])
        {
            maxPos[h] = i;
            h--;
        }
    }
    int best = 0;
    for(int i = 0; i < m - 1; i++)
    {
        int op1 = minPos[i];
        int op2 = maxPos[i+1];
        best = max(best, op2-op1);
    }
    cout << best << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
