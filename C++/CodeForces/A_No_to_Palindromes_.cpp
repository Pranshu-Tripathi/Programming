#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, p;
    cin >> n >> p;
    char lim = p + 96;
    vector<char> pssble;
    for (char i = 'a'; i <= lim; i++)
        pssble.push_back(i);
    string s;
    cin >> s;
    // if(p<=3&&s.size()>=3){
    //     cout<<"NO\n";
    //     return 0;
    // }
    int idx = -1;
    for (int i = n - 1; i >= 0; i--)
    {
        char check = s[i] + 1;
        bool flag = false;
        while (check <= lim)
        {
            if (i >= 2 && check != s[i - 1] && check != s[i - 2])
            {
                idx = i;
                s[i] = check;
                flag = true;
                break;
            }
            if (i == 1 && check != s[i - 1])
            {
                idx = i;
                s[i] = check;
                flag = true;
                break;
            }
            if (i == 0)
            {
                idx = i;
                s[i] = check;
                flag = true;
                break;
            }

            check++;
        }
        if (flag)
            break;
    }
    if (idx == -1)
    {
        cout << "NO\n";
        return 0;
    }
    //cout<<idx<<endl;
    for (int i = idx + 1; i < n; i++)
    {
        int j = 0;
        while (j < pssble.size())
        {
            if (pssble[j] != s[i - 1] && pssble[j] != s[i - 2])
            {
                s[i] = pssble[j];
                break;
            }
            j++;
        }
    }
    cout << s;
}