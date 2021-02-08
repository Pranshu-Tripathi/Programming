#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

char dir[4] = {'L','R','U','D'};

void move(int dist, char d)
{
    printf("1 %d %c\n",dist,d);
}

void pickBomb()
{
    printf("2\n");
}

void destroyBomb()
{
    printf("3\n");
}

bool distanceFromOrigin(const pair<ll,ll>& a, const pair<ll,ll>& b)
{
    // ll dist_A = a.first * a.first + a.second* a.second;
    // ll dist_B = b.first * b.first + b.second* b.second;
    ll dist_A = abs(a.first) + abs(a.second);
    ll dist_B = abs(b.first) + abs(b.second);
    return dist_A < dist_B;
}

void _run()
{
    int n;
    cin >> n;
    vector<pair<ll,ll>> points(n);
    int axialPoints = 0;
    int totalOps = 0;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> points[i].first >> points[i].second;
        if(points[i].first == 0 || points[i].second == 0)
            axialPoints++;
    }

    totalOps = axialPoints * 4 + (n - axialPoints) *6;

    cout << totalOps << endl;

    sort(points.begin(),points.end(), distanceFromOrigin);

    for(int i = 0 ; i < n ; i++)
    {
        if(points[i].first * points[i].second > 0)
        {
            // 1st or 3rd quadrant
            if(points[i].first < 0)
            {
                // 3rd quadrant
                move(abs(points[i].second),dir[3]);
                move(abs(points[i].first),dir[0]);
                pickBomb();
                move(abs(points[i].second),dir[2]);
                move(abs(points[i].first),dir[1]);
                destroyBomb();
            }
            else
            {
                // 1st quadrant
                move(abs(points[i].second),dir[2]);
                move(abs(points[i].first),dir[1]);
                pickBomb();
                move(abs(points[i].second),dir[3]);
                move(abs(points[i].first),dir[0]);
                destroyBomb();
            }
        }
        else if(points[i].first * points[i].second < 0)
        {
            // 2nd or 4th quadrant
            if(points[i].first < 0)
            {
                // 2nd quadrant
                move(abs(points[i].second),dir[2]);
                move(abs(points[i].first),dir[0]);
                pickBomb();
                move(abs(points[i].second),dir[3]);
                move(abs(points[i].first),dir[1]);
                destroyBomb();
            }
            else
            {
                // 4th quadrant
                move(abs(points[i].second),dir[3]);
                move(abs(points[i].first),dir[1]);
                pickBomb();
                move(abs(points[i].second),dir[2]);
                move(abs(points[i].first),dir[0]);
                destroyBomb();
            }
        }
        else
        {
            // axial point
            if(points[i].first == 0)
            {
                // y axis point
                move(abs(points[i].second),(points[i].second > 0 ? dir[2] : dir[3]));
                pickBomb();
                move(abs(points[i].second),(points[i].second > 0 ? dir[3] : dir[2]));
                destroyBomb();
            }
            else
            {
                // x axis point
                move(abs(points[i].first) , (points[i].first > 0 ? dir[1] : dir[0]));
                pickBomb();
                move(abs(points[i].first) , (points[i].first > 0 ? dir[0] : dir[1]));
                destroyBomb();
            }
        }
    }

}

int main()
{
    fast;
    int test = 1;
    while(test--)
        _run();
    return 0;
}
