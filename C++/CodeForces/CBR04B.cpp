#include<bits/stdc++.h>
using namespace std;
#define ll long long

const string no = "NO";
const string yes = "YES";

void _run()
{
    int d,sumTime;
    cin >> d >> sumTime;
    vector<pair<int,int>> limits(d);
    int ans[d];
    int sumMin = 0,sumMax = 0;
    for(int i = 0 ; i < d ; i++)
        cin >> limits[i].first >> limits[i].second, sumMax += limits[i].second, sumMin += limits[i].first, ans[i] = limits[i].second;
    
    if(sumMin > sumTime || sumMax < sumTime)
    {
        cout << no << endl;
        return;
    }

    int etras = abs(sumTime - sumMax);
    for(int i = 0 ; i < d ; i++)
    {
        if(etras == 0)
            break;
        int posssibility = limits[i].second - limits[i].first;
        if(posssibility <= etras)
            ans[i] = limits[i].first, etras -= posssibility;
        else
            ans[i] -= etras, etras = 0;
    }

    if(etras != 0)
    {
        cout << no << endl;
        return;
    }

    cout << yes << endl;
    for(auto x : ans)
        cout << x << ' ';
    cout << endl;
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