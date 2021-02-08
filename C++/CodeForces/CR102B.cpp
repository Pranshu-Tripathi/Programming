#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios::sync_with_stdio(false); \
                    cin.tie(NULL);

void _run()
{
    string s;
    cin >> s;
    string fraction = "";
    string integer = "";
    if(s[0] == '-')
    {
        int i;
        int integral = 0;
        for(i = 1 ; i  < s.length() ; i++)
        {
            if(s[i] == '.')
                break;
            if(s[i] != ',')
                integral++,integer+=s[i];
        }
        fraction += (i+1 < s.length())?s[i+1]:'0';
        fraction += (i+2 < s.length())?s[i+2]:'0';
        string inte = "";
        int count = 0;
        for(int j = integral - 1; j >= 0 ; j--)
        {
            if(count % 3 == 0 && count != 0)
                inte += ',';
            inte += integer[j];
            count++;
        }
        reverse(inte.begin(),inte.end());
        cout << "($" << inte << '.' << fraction<<')' << endl;
    }
    else
    {
        int i;
        int integral = 0;
        for(i = 0 ; i  < s.length() ; i++)
        {
            if(s[i] == '.')
                break;
            if(s[i] != ',')
                integral++,integer+=s[i];
        }
        fraction += (i+1 < s.length())?s[i+1]:'0';
        fraction += (i+2 < s.length())?s[i+2]:'0';
        string inte = "";
        int count = 0;
        for(int j = integral - 1; j >= 0 ; j--)
        {
            if(count % 3 == 0 && count != 0)
                inte += ',';
            inte += integer[j];
            count++;
        }
        reverse(inte.begin(),inte.end());
        cout << '$' << inte << '.' << fraction<< endl;
    }
}

int main()
{
    int test = 1;
    while(test--)
        _run();
    return 0;
}