#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

const string yes= "YES";
const string no = "NO";

void _run()
{
    int xf,yf;
    string s;
    cin>>xf>>yf>>s;
    map<char, int> mp;
    for(int i = 0; i < s.length();i++)
    {
        mp[s[i]]++;
    }
    int flag = 0;
    if(yf >= 0)
    {
        if(mp['U'] >= yf)
        {
            flag++;
        }
    }
    else
    {
        if(mp['D'] >= abs(yf))
        {
            flag++;
        }
    }
    if(xf >= 0)
    {
        if(mp['R'] >= xf)
        {
            flag++;
        }
    }
    else
    {
        if(mp['L'] >= abs(xf))
        {
            flag++;
        }
    }
    if(flag == 2)
    {
        cout << yes << endl;;
        return;
    }
    cout<< no << endl;
}

int main()
{
    fast;
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
