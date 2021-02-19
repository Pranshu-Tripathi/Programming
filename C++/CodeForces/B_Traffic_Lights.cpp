#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

void _run()
{
    int l,d,v,g,r;
    cin >> l >> d >> v >> g >> r;
    double timeToReachSignal = (double)d/v;
    double timeToReachDestination;
    bool signalGreen = true;
    int timeCheck = 0;
    while(timeCheck <= timeToReachSignal)
    {
        if(signalGreen)
        {
            timeCheck += g;
            signalGreen = false;
        }
        else
        {
            timeCheck += r;
            signalGreen = true;
        }
    }
    
    if(signalGreen)
    {
        // Reached signal at red signal
        timeToReachSignal = timeCheck;
        timeToReachDestination = (double)(l-d)/v;
    }
    else
    {
        timeToReachDestination = (double)(l-d)/v;
    }

    cout.precision(20);

    cout << timeToReachDestination + timeToReachSignal << endl;

}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
