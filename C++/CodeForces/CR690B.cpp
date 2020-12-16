#include<bits/stdc++.h>
using namespace std;

string yes = "YES";
string no = "NO";

bool secondPart(string s,int n)
{
    return (s[n-1] == '0') &&  (s[n-2] == '2') && (s[n-3] == '0') && (s[n-4] == '2');   
}

bool firstPart(string s,int n)
{
    return (s[0] == '2') &&  (s[1] == '0') && (s[2] == '2') && (s[3] == '0');
}

bool part3(string s, int n)
{
    return (s[0] == '2') && (s[n-3] == '0') && s[n-2] == '2' && s[n-1] =='0';
}

bool part4(string s, int n)
{
    return  (s[0] == '2') && (s[1] == '0') && s[n-2] == '2' && s[n-1] =='0';
}

bool part5(string s, int n)
{
    return (s[0] == '2') && (s[1] == '0') && s[2] == '2' && s[n-1] =='0';
}

void run_testcase()
{

    int n;
    cin >> n;
    string s;
    cin >> s;

    if(n < 4)
    {
        cout << no <<endl;
        return;
    }

    bool pos = false;

    pos = firstPart(s,n) || secondPart(s,n) || part3(s,n) || part4(s,n) || part5(s,n);

    if(pos)
        cout << yes << endl;
    else
        cout << no << endl;
}

int main()
{
    int test;
    cin >> test;
    while(test--)
        run_testcase();
    
    return 0;
}