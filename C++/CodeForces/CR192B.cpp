#include<bits/stdc++.h>
using namespace std;

void _run()
{
    int n,m;
    cin >> n >> m;
    cout << n -1 << endl;
    vector<pair<int,int>> no(m);
    vector<bool> CentralNode(n+1,true);
    for(int i = 0 ; i < m ; i++)
        cin >> no[i].first >> no[i].second,CentralNode[no[i].first] = CentralNode[no[i].second] = false;
    
    
    int ind = -1;
    for(int i = 1 ; i <= n ; i++)
        if(CentralNode[i])
        {
            ind = i;
            break;
        }
    
    for(int i = 1 ; i <= n ; i++)
        if(i != ind)
            cout << ind << " " << i << endl;

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