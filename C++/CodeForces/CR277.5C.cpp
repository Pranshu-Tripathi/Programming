#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

const string num = "0123456789";

bool possible(int digits, int sum)
{
    return sum >= 0 && sum <= digits*9;
}


void _run()
{
    int m , s;
    cin >> m >> s;
    
    if((s < 1 && m > 1)|| s > m * 9)
    {
        cout << -1 << " " << -1 << endl;
        return;
    }

    string ansMin ="";
    int sumMin = s;
    for(int i = 0 ; i < m ; i++)
    {
        if(i == 0 && m > 1)
        {
            for(int j = 1 ; j < 10 ; j++)
            {
                if(possible(m-1,sumMin-j))
                {
                    ansMin += num[j];
                    sumMin -= j;
                    break;
                }
            }
        }
        else
        {
            for(int j = 0; j <= 9 ; j++)
            {
                if(possible(m-i-1,sumMin - j))
                {
                    ansMin += num[j];
                    sumMin -= j;
                    break;
                }
            }
        }
    }

    cout << ansMin << " ";

    int sumMax = s;
    string ansMax = "";

    for(int i = 0 ; i < m ; i++)
    {
        if(i == 0 && m > 1)
        {
            for(int j = 9 ; j > 0 ; j--)
            {
                if(possible(m-1,sumMax - j))
                {
                    ansMax += num[j];
                    sumMax -= j;
                    break;
                }
            }
        }
        else
        {
            for(int j = 9  ; j >= 0 ; j--)
            {
                if(possible(m-i-1,sumMax-j))
                {
                    ansMax += num[j];
                    sumMax -= j;
                    break;
                }
            }
        }
    }

    cout << ansMax;
    
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
