#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long I[3][3], T[3][3];
long long ar[3];
int n;

void mult(long long int A[3][3], long long int B[3][3], int dim)
{
    long long int res[3][3];
    for(int i = 1 ; i <= dim ; i++)
    {
        for(int j = 1 ; j <= dim ; j++)
        {
            res[i][j] = 0;
            for(int k = 1 ; k <= dim ; k++)
            {
                long long int x = (A[i][k] * B[k][j])%mod;
                res[i][j] = (res[i][j] + x)%mod;
            }
        }
    }

    for(int i = 1 ; i <= dim ; i++)
        for(int j = 1 ; j <= dim ; j++)
            A[i][j] = res[i][j];
}



int main()
{
    cin >> ar[1] >> ar[2];
    cin >> n;
    I[1][1] = I[2][2] = 1;
    I[1][2] = I[2][1] = 0;
    T[1][1] = 0;
    T[2][2] = T[2][1] = T[1][2] = 1;
    n--;
    while(n)
    {
        if(n&1)
            mult(I,T,2),n--;
        else
            mult(T,T,2),n/=2;
    }
    long long fn = (ar[1] * I[1][1] + ar[2] * I[2][1])%mod;
    cout << fn <<endl;
}
