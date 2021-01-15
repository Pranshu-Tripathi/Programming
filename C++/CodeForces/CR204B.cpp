#include<bits/stdc++.h>
using namespace std;

void _run()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0 ; i < n ; i++)
        cin >> a[i];

    int commonRatio[100005] ;
    int lastOccurenec[100005];

    memset(commonRatio,-1,sizeof(commonRatio));
    memset(lastOccurenec,-1,sizeof(lastOccurenec));

    for(int i = 0 ; i < n ; i++)
    {
        if(commonRatio[a[i]] == -1)
        {
            commonRatio[a[i]] = 0;
            lastOccurenec[a[i]] = i;
        }
        else if(commonRatio[a[i]] == 0)
        {   
            int first = 0;
            commonRatio[a[i]] = i - lastOccurenec[a[i]];
        }
        else if(commonRatio[a[i]] == -2)
        {
            continue;
        }
        else
        {
            if(a[i] != a[i-commonRatio[a[i]]])
                commonRatio[a[i]] = -2;
        }
        // for(int i = 1 ; i <= 5 ; i++)
        //     cout << commonRatio[i] << ' ';
        // cout << endl;
    }


    set<int> elements;
    for(int i = 0 ; i < n ; i++)
        elements.insert(a[i]);
    int elle = 0;
    for(int i  : elements)
        if(commonRatio[i] != -2 && commonRatio[i] != -1)
            elle++;
    
    cout << elle << endl;
    for(int i : elements)
    {
        if(commonRatio[i] != -2 && commonRatio[i] != -1)
            cout << i << ' ' << commonRatio[i] << endl;
    }
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