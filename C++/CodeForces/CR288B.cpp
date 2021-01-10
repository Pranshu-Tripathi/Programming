#include<bits/stdc++.h>
using namespace std;
#define ll long long

void digits(string n,vector<int>& ans)
{
    for(int i = 0 ; i < n.length() ; i++)
    {
        ans.push_back((int)n[i] - (int)'0');
    }
}

void _run()
{
    string n;
    cin >> n;
    vector<int> d;
    digits(n,d);
    int last = d[d.size() - 1];
    bool swa = false;
    int evenIdx = -1;
    for(int i = 0 ; i < d.size() ; i++)
    {
        if(last > d[i] && d[i] % 2 == 0)
        {
            
            swap(d[i],d[d.size() - 1]);
            swa = true;
            break;
        }
        if(d[i] % 2 == 0)
            evenIdx = i;
    }
    if(!swa && evenIdx == -1)
    {
        cout << evenIdx << endl;
        return;
    }
    else if(!swa)
    {
        swap(d[evenIdx],d[d.size() - 1]);
    }

    for(auto x : d)
        cout << x;
    cout << endl;
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    while(test--)
        _run();
    return 0;
}
