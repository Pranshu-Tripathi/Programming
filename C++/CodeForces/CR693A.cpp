#include<bits/stdc++.h>
using namespace std;

string no = "NO";
string yes = "YES";

void _run()
{
    int w,h,n;
    cin >> w >> h >> n;

    long long fact = 1;
    while(true)
    {   
        if(w % 2 != 0 && h % 2 != 0 )
        {
            break;
        }
        if(w % 2 == 0)
        {
            w /= 2;
        }
        else
        {
            h /= 2;
        }
        fact *= 2;
    }
     
    if(fact >= n)   
        cout << yes << endl;
    else 
        cout << no << endl;

    return;

}

int main()
{
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}