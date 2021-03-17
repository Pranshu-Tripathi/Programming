#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<char> dict = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};

char getChar(string x)
{
    int index = 0;
    int fact = 1;
    for(int i = 3 ; i >= 0 ; i--)
    {
        if(x[i] == '1')
        {
            index += fact;
        }
        fact *= 2;
    }

    return dict[index];
}

void _run()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<char> ans;
    vector<string> enco;
    string x = "";
    for(int i = 1 ; i <= n ; i++)
    {
        if(i % 4 == 0)
        {
            x += s[i-1];
            enco.push_back(x);
            x = "";
        }
        else
        {
            x += s[i-1];
        }
    }

    for(int i = 0 ; i < enco.size() ; i++)
    {
        ans.push_back(getChar(enco[i]));
    }

    for(auto c : ans)
        cout << c;
    
    cout << endl;

}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
