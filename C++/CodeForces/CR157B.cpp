#include<bits/stdc++.h>
using namespace std;
#define ll long long


void _run()
{
    int mat[3][3];
    for(int i = 0 ; i < 3 ; i++)
        for(int j = 0 ; j < 3 ; j++)
            cin >> mat[i][j];
    
    mat[0][0] = ((mat[2][0] + mat[2][1] + mat[1][0] + mat[1][2])-(mat[0][1] + mat[0][2]))/2;
    mat[1][1] = mat[2][0] + mat[2][1]  - mat[0][0];
    mat[2][2] = mat[0][1] + mat[0][2] - mat[1][1];

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j ++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
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
