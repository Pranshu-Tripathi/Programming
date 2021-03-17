#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define ld long double
#define mod 1000000009

void _run()
{
    int n;
    cin >> n;
    vector<int>t1;
    vector<int> t2;
    vector<int> t3;
    for(int i = 1 ; i <= n ;i++)
    {
        int t;
        cin >> t;
        if(t == 1)
            t1.push_back(i);
        else if(t == 2)
            t2.push_back(i);
        else
            t3.push_back(i);
    }

    int size = min(t1.size(),min(t2.size(),t3.size()));

    cout << size << endl;
    for(int i = 0; i < size ; i++)
        cout << t1[i] << ' ' << t2[i] << ' ' << t3[i]  << endl;


}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
