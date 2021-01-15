#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int n;
    cin >> n;
    int homeKit[n];
    int awayKit[n];
    vector<pair<int,int>> answer(n);
    int freqHomeKit[100005];
    memset(freqHomeKit,0,sizeof(freqHomeKit));
    for(int i = 0 ; i < n ; i++)
    {
        cin >> homeKit[i] >> awayKit[i];
        freqHomeKit[homeKit[i]]++;
    }

    for(int i = 0 ; i < n ; i++)
    {
        int home = n -1;
        home += freqHomeKit[awayKit[i]];

        int away = 2*(n-1) - home;
        answer[i].first = home, answer[i].second = away;
    }

    for(auto team : answer)
        cout << team.first << " " << team.second << endl;

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
