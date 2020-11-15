#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0) , cin.tie(0),cout.tie(0);
#define ll long long
#define endl "\n"
#define And &&
#define Or ||
#define FOR(i,a,b)              for(int i = a; i < b; i++)
#define REV(i,a,b)              for(int i = a; i >= b; i--)
#define FORE(i,a,b)             for(int i = a; i <= b; i++)
#define pii                     pair<int,int>
#define pll                     pair< long long int, long long int> 
typedef 						long double ld;
typedef 						unsigned long long ull;
#define F                       first
#define S                       second
#define pb                      push_back

long long int x1;
long long int x2;
long long int Y1;
long long int y2;

bool boundary(ll x, ll y , map<pair<ll,ll>,ll> vis)
{
    if(x1 > -10 And x1 < 10 And  Y1 < 10 And x2 > -10 And x2 < 10 And y2 < 10)
    {
        if (x <= -10 || x >= 10 || y <= 0 || y >= 10)
            return false;
        if (vis.find({x, y}) != vis.end())
            return false;
        return true;
    }
    else
    {
        if (x < -1000000000000000 || x > 1000000000000000 || y < 0 || y > 1000000000000000)
            return false;
        if (vis.find({x, y}) != vis.end())
            return false;
        return true;
    }
}


void BFS_SSSP()
{
    if(x1 == x2 And Y1 == y2)
    {
        cout << 0 << endl;
        return;
    }

    queue <pair<ll,ll>> queue;
    map <pair<ll,ll>,ll> distance,vis;

    queue.push({x1,Y1});

    distance[{x1,Y1}] = 0;
    vis[{x1,Y1}] = 1;



    while(!queue.empty())
    {
        ll X = queue.front().F;
        ll Y = queue.front().S;

        queue.pop();

        if(boundary(X + 2* Y,Y,vis))
        {
            ll _X = X + 2 * Y;
            ll _Y = Y;

            if(_X == x2 And _Y == y2)
            {
                cout << distance[{X,Y}] +1<< endl;
                return;
            }
            distance[{_X,_Y}] = distance[{X,Y}] + 1;
            vis[{_X,_Y}] = 1;
            queue.push({_X,_Y});
        }

        if(boundary(X - 2 * Y,Y,vis))
        {
            ll _X = X - 2 * Y;
            ll _Y = Y;

            if(_X == x2 And _Y == y2)
            {
                cout << distance[{X,Y}] + 1 << endl;
                return;
            }

            distance[{_X,_Y}] = distance[{X,Y}]+1;
            vis[{_X,_Y}] = 1;
            queue.push({_X,_Y});
        }

        if(Y + 2 * X < 0)
        {
            if(boundary(-X,-(Y+2*X),vis))
            {
                ll _X = -X;
                ll _Y = - ( Y + 2 * X);

                if(_X == x2 And _Y == y2)
                {
                    cout << distance[{X,Y}] +1<< endl;
                    return;
                }

                distance[{_X,_Y}] = distance[{X,Y}]+1;
                vis[{_X,_Y}] = 1;
                queue.push({_X,_Y});
            }
        }
        else
        {
            if(boundary(X,(Y+2*X),vis))
            {
                ll _X = X;
                ll _Y = Y+2*X;

                if(_X == x2 And _Y == y2)
                {
                    cout << distance[{X,Y}] +1<< endl;
                    return;
                }

                distance[{_X,_Y}] = distance[{X,Y}]+1;
                vis[{_X,_Y}] = 1;
                queue.push({_X,_Y});
            }
        }
        if(Y - 2 * X < 0)
        {
            if(boundary(-X,-(Y - 2 * X),vis))
            {
                ll _X = - X;
                ll _Y = - (Y - 2 * X);

                if(_X == x2 And _Y == y2)
                {
                    cout << distance[{X,Y}] +1<< endl;
                    return;
                }
                distance[{_X,_Y}] = distance[{X,Y}]+1;
                vis[{_X,_Y}] = 1;
                queue.push({_X,_Y});
            }
        }
        else
        {
            if(boundary(X, Y - 2 * X, vis))
            {
                ll _X = X;
                ll _Y = Y - 2 * X;
                if(_X == x2 And _Y == y2)
                {
                    cout << distance[{X,Y}] +1<< endl;
                    return;
                }
                distance[{_X,_Y}] = distance[{X,Y}]+1;
                vis[{_X,_Y}] = 1;
                queue.push({_X,_Y});
            }
        }   
    }
}

void testcase()
{
    cin >> x1 >> Y1 >> x2 >> y2;

    BFS_SSSP();
}


int main()
{
    int test;
    cin >> test;
    while(test--)
    {
        testcase();
    }
}