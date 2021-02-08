#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

const string wa = "WA";
const string acc = "ACC";

bool findStr(string&s , vector<string>& com)
{
    
    for(int i = 0 ; i < com.size() ; i++)
    {
        //cout << com[i] << ' ' << s << endl;
        if(com[i] == s)
            return true;
    }
    return false;
}


void toLowerCase(string& s)
{
    for(int i = 0 ; i < s.length() ; i ++)
    {
        if(s[i] < 97)
        {
            s[i] = ('a' + (s[i] - 'A'));
        }
    }
}

void _run()
{
    string inp;
    vector<string> s(3,"");

    for(int i = 0 ; i < 3 ; i ++)
    {
        cin >> inp;
        for(int j = 0 ;  j < inp.length() ; j++)
        {
            if(inp[j] == ';' || inp[j] == '-' || inp[j] == '_')
                continue;
            else
                s[i] += inp[j];
        }
        //cout << s[i] << endl;
    }

    vector<string> comni(6,"");

    comni[0] += s[0] + s[1] + s[2];
    comni[1] += s[0] + s[2] + s[1];
    comni[2] += s[1] + s[2] + s[0];
    comni[3] += s[1] + s[0] + s[2];
    comni[4] += s[2] + s[0] + s[1];
    comni[5] += s[2] + s[1] + s[0];

    for(int i = 0 ; i < 6 ; i ++)
        toLowerCase(comni[i]);

    int stu;
    cin >> stu;
    for(int i = 0 ; i < stu ; i ++)
    {
        string student = "";
        cin >> inp;
        for(int j = 0 ;  j < inp.length() ; j++)
        {
            if(inp[j] == ';' || inp[j] == '-' || inp[j] == '_')
                continue;
            else
                student+= inp[j];
        }
        toLowerCase(student);
        if(findStr(student,comni))
            cout << acc << endl;
        else 
            cout << wa << endl;
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
