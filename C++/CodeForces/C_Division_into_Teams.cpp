#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

void _run()
{
    int n;
    cin >> n;
    vector<pair<int,int>> p(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> p[i].first;
        p[i].second = i;
    }
    sort(p.begin(),p.end());
    vector<int> A,B;    
    int c = n;
    if(n % 2 != 0)
        c--;
    ll sumA = p[0].first;
    A.push_back(p[0].second);
    ll sumB = p[1].first;
    B.push_back(p[1].second);
    int pairs = n/2 - 1;
    int i = 2;
    //cout << sumA << ' ' << sumB << endl;
    while(pairs--)
    {
        if(sumA < sumB)
        {
            A.push_back(p[i+1].second);
            B.push_back(p[i].second);
            sumA += p[i+1].first;
            sumB += p[i].first;
        }
        else
        {
            A.push_back(p[i].second);
            B.push_back(p[i+1].second);
            sumA += p[i].first;
            sumB += p[i+1].first;
        }
        i += 2;
    }

    if(c != n)
    {
        if(sumA <= sumB)
        {
            A.push_back(p[n-1].second);
            sumA += p[n-1].first;
        }
        else
        {
            B.push_back(p[n-1].second);
            sumB += p[n-1].first;
        }
    }
    //cout << sumA << ' ' << sumB << endl;



    //cout << "****************ANSWER K***********" << endl;
    cout << A.size() << endl;
    //sort(A.begin(),A.end());

    for(auto pla : A)
        cout << pla + 1 << ' ';
    cout << endl;

    cout << B.size() << endl;
    //sort(B.begin(),B.end());
    for(auto pla : B)
        cout << pla +1  << ' ';
    cout << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
