#include<bits/stdc++.h>
using namespace std;
#define ll long long

void _run()
{
    int n,m,d;
    cin >> n >> m >> d;
    int a[n][m];
    set<int> modulos;
    vector<int> ele;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> a[i][j];
            ele.push_back(a[i][j]);
            modulos.insert(a[i][j] % d);
        }
    }

    if(modulos.size() > 1)
    {
        cout << -1 << endl;
        return;
    }

    sort(ele.begin(),ele.end());
    int z = ele[ele.size()/2];
    ll sum = 0;
    for(int i = 0 ; i < ele.size() ; i++)
    {
        sum += abs(ele[i] - z);
    }

    cout << sum / d << endl;

}

int main()
{
    int test = 1;
    while(test--)
        _run();
    return 0;
}