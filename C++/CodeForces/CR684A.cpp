#include<bits/stdc++.h>
using namespace std;

void run_test()
{
    int n,c0,c1,h;
    string s;
    vector<int> fin;
    cin >> n >> c0 >> c1 >> h >> s;

    bool change1 = (c0 + h < c1);
    bool change0 = (c1 + h < c0);

    for(char b : s)
    {
        if(b == '1')
        {
            if(change1)
                fin.push_back(c0+h);
            else
                fin.push_back(c1);
        }
        else
        {
            if(change0)
                fin.push_back(c1+h);
            else
                fin.push_back(c0);     
        }
    }
    int cost = 0;
    for(int element : fin)
        cost+= element;
    cout << cost << endl;

    return;
}

int main()
{
    int test;
    cin >> test;
    while(test--)
        run_test();
    return 0;
}