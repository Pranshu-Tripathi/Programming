#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int na,ma;
    cin >> na >> ma;
    int a[na][ma];
    for(int i = 0 ; i < na ; i++)
        for(int j = 0 ; j < ma ; j++)
        {
            char ch;
            cin >> ch;
            a[i][j] = ch - '0';
        }
    int nb,mb;
    cin >> nb >> mb;
    int b[nb][mb];
    for(int i = 0 ; i < nb ; i++)
        for(int j = 0 ; j < mb ; j++)
        {   char ch;
            cin >> ch; 
            b[i][j] = ch - '0';
        }
    
    int mx , my, sum = -1;

    for(int x = -50 ; x <= 50 ; x++)
    {
        for(int y = -50 ; y <= 50 ; y++)
        {
            int s = 0;
            for(int i = -min(0,x) ;i  < min(na,nb - x) ; i++)
            {
                for(int j = -min(0,y) ; j < min(ma,mb - y) ; j++)
                {
                    s += a[i][j] * b[i+x][j+y];
                }
            }
            if(sum < s)
                sum = s, mx = x , my = y;
        }
    }

    // for(int x = -50 ; x < 0 ; x++)
    // {
    //     for(int y = -50 ; y <0 ; y++)
    //     {
    //         int s = 0;
    //         for(int i = -x ;i  < na ; i++)
    //         {
    //             for(int j = -y ; j < min(ma,mb - y) ; j++)
    //             {
    //                 s += a[i][j] * b[i+x][j+y];
    //             }
    //         }
    //         if(sum < s)
    //             sum = s, mx = x , my = y;
    //     }
    // }


    cout << mx << ' ' << my << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
