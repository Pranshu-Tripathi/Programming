#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

vector<pair<int,int>> points(301);

double triangleArea(pair<int,int>&A, pair<int,int>& B , pair<int,int>& C)
{
    return ((double)(B.first - A.first) * (C.second - B.second) - (B.second - A.second) * (C.first - B.first)) * 0.5; 
}

void chmax(double &A, double B) {
    if (B - A > 0.000001)
        A = B;
}

void _run()
{
    int n;
    cin >> n;

    for(int i = 0 ; i < n ; i++)
    {
        int x,y;
        cin >> x >> y;
        points[i].first = x;
        points[i].second = y;
    }

    double maxArea = 0;
    for(int i = 0 ; i < n ; i++)
        for(int j = i+1 ;  j < n ; j++)
        {
            double maxMinus = - 1 , maxPlus = -1;
            for(int k = 0 ; k < n ; k++)
            {
                if(i != k && j != k)
                {
                    if(triangleArea(points[i],points[j],points[k]) < 0)
                        chmax(maxMinus,-triangleArea(points[i],points[j],points[k]));
                    else
                        chmax(maxPlus,triangleArea(points[i],points[j],points[k]));
                }   
            }
            // cout << maxPlus << ' ' << maxMinus << endl;
            if(maxPlus >= 0 && maxMinus >= 0)
                chmax(maxArea,maxPlus + maxMinus);
        }
    cout.precision(10);
    cout << maxArea << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
