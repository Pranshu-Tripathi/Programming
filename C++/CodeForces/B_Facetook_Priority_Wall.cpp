#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

const string posted = "posted";
const string com = "commented";
const string likes = "likes";

bool _sortingCondition(const pair<string,int>& a , const pair<string,int> & b)
{
    if(a.second == b.second)
        return a.first < b.first;
    
    return a.second > b.second;
}


void _run()
{
    string myName;
    cin >> myName;
    map<string,int> tally;
    int n;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        string s1,s2,s3,s4,s5,s6;
        cin >> s1 >> s2;
        if(s2 == posted)
        {
            cin >> s3 >> s4 >> s5;
            s6 = "";
            for(int i = 0 ; i < s4.length() ;i++)
            {
                if(s4[i] == '\'')
                    break;
                s6 += s4[i];
            }

            if(s1 == myName)
            {
                if(tally.find(s6) != tally.end())
                    tally[s6] += 15;
                else
                    tally[s6] = 15;
            }
            else if(s6 == myName)
            {
                if(tally.find(s1) != tally.end())
                   tally[s1] += 15;
                else
                    tally[s1] = 15;
            }
            else
            {
                if(tally.find(s1)  == tally.end())
                    tally[s1] = 0;
                if(tally.find(s6) == tally.end())
                    tally[s6] = 0;
            }
        }
        else if(s2 == com)
        {
            cin >> s3 >> s4 >> s5;
            s6 = "";
            for(int i = 0 ; i < s4.length() ;i++)
            {
                if(s4[i] == '\'')
                    break;
                s6 += s4[i];
            }
            if(s1 == myName)
            {
                if(tally.find(s6) != tally.end())
                    tally[s6] += 10;
                else
                    tally[s6] = 10;
            }
            else if(s6 == myName)
            {
                if(tally.find(s1) != tally.end())
                   tally[s1] += 10;
                else
                    tally[s1] = 10;
            }
            else
            {
                if(tally.find(s1)  == tally.end())
                    tally[s1] = 0;
                if(tally.find(s6) == tally.end())
                    tally[s6] = 0;
            }
        }
        else
        {
            cin >> s4 >> s3;
            s6 = "";
            for(int i = 0 ; i < s4.length() ;i++)
            {
                if(s4[i] == '\'')
                    break;
                s6 += s4[i];
            }
            if(s1 == myName)
            {
                if(tally.find(s6) != tally.end())
                    tally[s6] += 5;
                else
                    tally[s6] = 5;
            }
            else if(s6 == myName)
            {
                if(tally.find(s1) != tally.end())
                   tally[s1] += 5;
                else
                    tally[s1] = 5;
            }
            else
            {
                if(tally.find(s1)  == tally.end())
                    tally[s1] = 0;
                if(tally.find(s6) == tally.end())
                    tally[s6] = 0;
            }
        }
    }

    vector<pair<string,int>> table;
    for(auto i : tally)
    {
        table.push_back(i);
        //cout << i.first << ' ' << i.second << endl;
    }

    sort(table.begin(),table.end(), _sortingCondition);

    for(auto x : table)
        cout << x.first << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
