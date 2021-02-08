#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


void _run()
{
    int n,p;
    cin >> n >> p;
    string pal = "#";
    string s;
    cin >> s;
    pal+= s;
    if( p>n / 2)
    {
        reverse(s.begin(),s.end());
        p = n - p + 1;
    }

    int rightEnd = -1;
    int leftEnd = -1;
    for(int i = 1 ; i <= n / 2 ; i ++)
    {
        if(pal[i] != pal[n-i+1])
        {
            leftEnd = i;
            break;
        }
    }
    for(int j = n/2 ; j > 0 ; j--)
    {
        if(pal[j] != pal[n-j+1])
        {
            rightEnd = j;
            break;
        }
    }
    //cout << leftEnd << ' ' << rightEnd << endl;
    int moves = 0;
    if(leftEnd == -1 && rightEnd == -1)
    {
        cout << moves << endl;
        return;
    }
    if(leftEnd > p && rightEnd > p)
    {
        //cout << "only move Right\n";
        for(int i =  p ; i <= rightEnd ; i++)
        {
            if(pal[i] != pal[n-i+1])
            {
                int dir1= abs(pal[i] - pal[n-i+1]);
                int dir2 = 26 - dir1;
                moves += min(dir1,dir2);
                pal[i] = pal[n-i+1];
            }
            if(i != p)
                moves++;
            //cout << moves << endl;
        }
    }

    else if(leftEnd < p && rightEnd < p)
    {
        //cout << "only move Left\n";
        for(int i =  p ; i >= leftEnd ; i--)
        {
            if(pal[i] != pal[n-i+1])
            {
                int dir1= abs(pal[i] - pal[n-i+1]);
                int dir2 = 26 - dir1;
                moves += min(dir1,dir2);
                pal[i] = pal[n-i+1];
            }
            if(i != p)
                moves++;
        }
    }

    else if(abs(leftEnd - p) > abs(rightEnd - p))
    {
        //cout << "first move right then move left\n";
        int i;
        for(i = p ; i <= rightEnd ; i++)
        {
            if(pal[i] != pal[n-i+1])
            {
                int dir1= abs(pal[i] - pal[n-i+1]);
                int dir2 = 26 - dir1;
                moves += min(dir1,dir2);
                pal[i] = pal[n-i+1];
            }
            if(i != p)
                moves++;
            //cout << moves << endl;
        }
        moves += rightEnd - p ;
        for(int i =  p ; i >= leftEnd ; i--)
        {
            if(pal[i] != pal[n-i+1])
            {
                int dir1= abs(pal[i] - pal[n-i+1]);
                int dir2 = 26 - dir1;
                moves += min(dir1,dir2);
                pal[i] = pal[n-i+1];
            }
            if(i != p)
                moves++;
            //cout << moves << endl;
        }
        
    }
    else 
    {
        //cout << "first move left then move right\n";
        int i;
        for(int i =  p ; i >= leftEnd ; i--)
        {
            if(pal[i] != pal[n-i+1])
            {
                int dir1= abs(pal[i] - pal[n-i+1]);
                int dir2 = 26 - dir1;
                moves += min(dir1,dir2);
                pal[i] = pal[n-i+1];
            }
            if(i != p)
                moves++;
            //cout << moves << endl;
        }
        moves += p - leftEnd ;
        for(i = p ; i <= rightEnd ; i++)
        {
            if(pal[i] != pal[n-i+1])
            {
                int dir1= abs(pal[i] - pal[n-i+1]);
                int dir2 = 26 - dir1;
                moves += min(dir1,dir2);
                pal[i] = pal[n-i+1];
            }
            if(i != p)
                moves++;
            //cout << moves << endl;
        }
    }
     cout << moves << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
