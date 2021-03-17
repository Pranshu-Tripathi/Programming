#include<bits/stdc++.h>
using namespace std;

void _run()
{
    int n,m;
    cin >> n >> m;
    vector<int> A;
    vector<int> B;

    long long sum_A = 0,sum_B = 0;

    int a,b;

    for(int i = 0 ; i < n ; i++)
    {
        cin >> a;
        sum_A+=a;
        A.push_back(a);
    }

    for(int i = 0 ; i < m ; i++)
    {
        cin >> b ;
        sum_B += b;
        B.push_back(b);
    }

    int count = 0;
    int indA = 0,indB =0;
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<int>());
    while(sum_A <= sum_B && indA < n && indB < m)
    {
        int A_min = A[indA];
        int B_max = B[indB];
        if(A_min >= B_max)
        {
            cout << -1 << endl;
            return;
        }

        sum_A += B_max - A_min;
        sum_B -= B_max - A_min;
        count++;
        indA++,indB++;
    }
    if(sum_A <= sum_B)
    {
        cout << -1 << endl;
        return;
    }
    cout << count << endl;
}

int main()
{
    int test;
    cin >> test;

    while(test--)
        _run();
    return 0;
}