#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

int ans[1005];
int m;
bool avail[11];

bool dfs(int leftSum, int rightSum, int pos, int curr)
{
    //cout  <<  leftSum << ' ' << rightSum << ' ' << pos << ' ' << curr<< endl;
    if(pos % 2 == 0)
    {
        // right addition happened; 
        if(rightSum - leftSum > 0)
        {
            ans[pos] = curr;
            if(pos == m)
            {
                return true;
            }
            bool forwardFound = false;
            for(int i = 1 ; i <= 10 ; i++)
            {
                if(i != curr && avail[i])
                {
                    ans[pos+1] = i; 
                    forwardFound =  dfs(leftSum+i,rightSum,pos+1,i);
                    if(forwardFound)
                        return true;
                }
            }
            return false;
        }
        else
        {
            return false;
        }
    }
    else
    {
        // left addition happened;
        if(leftSum - rightSum > 0)
        {
            ans[pos] = curr;
            if(pos == m)
            {
                return true;
            }

            bool forwardFound = false;
            for(int i = 1 ; i <= 10 ; i++)
            {
                if(i != curr && avail[i])
                {
                    ans[pos+1] = i;
                    forwardFound = dfs(leftSum,rightSum+i,pos+1,i);
                    if(forwardFound)
                        return true;
                }
            }
            return false;
        }
        else
        {
            return false;
        }
    }
}


void _run()
{
    string s;
    cin >> s;
    cin >> m;
    for(int i = 0 ;i < s.length() ; i++)
        if(s[i] == '1')
            avail[i+1] = true;

    for(int i = 1 ; i <= 10 ; i++)
    {
        if(avail[i])
        {
            memset(ans,-1,sizeof(ans));
            if(dfs(i,0,1,i))
            {
                cy;
                for(int i = 1 ; i<= m ; i++)
                    cout << ans[i]  << ' ';
                return;
            }
        }
    }

    cn;

}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
