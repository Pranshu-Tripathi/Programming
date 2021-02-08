#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

int monthCount[12] = {31,28,31,30,31,30,31,31,30,31,30,31}; 
string inp, ans;

int datemonthRet(char c, char d)
{
    return ((c-'0') * 10)+ ((d-'0') *1);
}

int yearRet(char a,char b, char c, char d)
{
   return ((a - '0')*1000 + (b-'0')*100 + (c-'0')*10+ (d-'0') *1);
}

bool isValidDate(int l, int r)
{
    // for(int i = l ;  i <= r ; i ++)
    //     cout << inp[i];
    // cout << ' ';
    if(inp[l+2] != '-' || inp[l+5] != '-')
    {
        //cout << "Issue Dash" << endl;
        return false;
    }
    int dash = 0;
    for(int i = l ; i <= r ; i++)
        if(inp[i] == '-')
            dash++;
    
    if(dash > 2)
    {
        //cout << "Issue Dash" << endl;
        return false;
    }
    int date = datemonthRet(inp[l],inp[l+1]);
    int month = datemonthRet(inp[l+3],inp[l+4]);
    if(month < 1 || month > 12)
    {
        //cout << "Issue Month" << endl;
        return false;
    }
    if(date > monthCount[month - 1] || date < 1)
    {
        //cout << "Issue Date " << date << ' ' << monthCount[month-1]  << ' ' << month << endl;
        return false;
    }
    int year = yearRet(inp[r-3],inp[r-2],inp[r-1],inp[r]);
    if(year < 2013 || year > 2015)
    {
        // cout << "Issue Year" << endl;
        return false;
    }
    //cout << "Accepted" << endl;  
    return true;
}

void _run()
{
    cin >> inp;
    int mxCount = -1;
    vector<string> correctdates;
    map<string, int> m;
    for(int l = 0 ; l + 9 < inp.length() ; l++)
    {
        if(isValidDate(l,l+9))
        {
            string s = "";
            for(int i = l ; i <= l + 9 ; i++)
                s += inp[i];
            correctdates.push_back(s);
        }
    }
    for(string & pat : correctdates)
    {
        if(m.find(pat) == m.end())
        {
            m[pat] = 1;
            if(mxCount < m[pat])
            {
                mxCount = m[pat];
                ans = pat;
            }
        }
        else
        {
            m[pat]++;
            if(mxCount < m[pat])
            {
                mxCount = m[pat];
                ans = pat;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
