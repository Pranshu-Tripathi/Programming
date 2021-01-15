#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int p,q,l,r;
    cin >> p >> q >> l >> r;

    vector<pair<int,int>> pi,qi;
    int x,y;
    for(int i = 0 ; i < p ; i++)
    {
        cin >> x >> y;
        pi.push_back({x,y});
    }
    for(int i = 0 ; i < q ; i++)
    {
        cin >> x >> y;
        qi.push_back({x,y});
    }

    // for(auto c : pi)
    // {
    //     cout << c.first << " & " << c.second << endl;
    // }

    // for(auto c : qi)
    // {
    //     cout << c.first << " ? " << c.second << endl;
    // }

    set<int> tis;
    for(int i = l ; i <= r ; i++)
    {
        for(int j = 0 ; j < q ; j++)
        {
            int sta = qi[j].first + i;
            int en = qi[j].second + i;
            for(int k = 0 ; k < p ; k++)
            {
                if(sta >= pi[k].first && sta <= pi[k].second)
                    tis.insert(i);
                if(en >= pi[k].first && en <= pi[k].second)
                    tis.insert(i);
                if(pi[k].first >= sta && pi[k].second <= en)
                    tis.insert(i);
            }
        }
    }
    int intervals = tis.size();

    // for(auto t : tis)
    //     cout << t << " ";
    cout << endl << intervals << endl;
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
