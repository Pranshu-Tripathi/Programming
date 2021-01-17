#include<bits/stdc++.h>
using namespace std;
#define ll long long

int nfre[26];
int mfre[26];

void _run()
{
    string n,m;
    cin >> n >> m;
    set<char> elem;
    for(int i = 0 ; i < n.length() ; i++)
        nfre[n[i] - 'a']++;
    for(int i = 0 ; i < m.length() ; i++)
        mfre[m[i] - 'a']++,elem.insert(m[i]);
    
    int area = 0;

    for(char ch : elem)
    {
        if(nfre[ch - 'a'] == 0)
        {
            cout << -1 << endl;
            return;
        }
        if(nfre[ch - 'a'] >= mfre[ch-'a'])
        {
            area += mfre[ch-'a'];
        }
        else
        {
            area += nfre[ch-'a'];
        }
    }

    cout << area << endl;
     
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;
    while(test--)
        _run();
    return 0;
}