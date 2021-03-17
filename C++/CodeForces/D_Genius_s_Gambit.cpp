#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "No" << endl
#define ld long double
#define mod 1000000009

// a zeroes and b ones;

void _run()
{    
    int a,b,k;
    cin >> a >> b >> k;

    if(a == 0 && k != 0 )
    {
        if(b != 1)
        {   
            cn;
            //cout << '%' << endl;
            return;
        }
    }

    if(b == 1 && k > 0) 
    {
        cn;
        //cout << '$' << endl;
        return;
    }

    if(k > a+b-2 && a+b-2 >= 0)
    {
        cn;
        //cout << '@' << endl;
        return;
    }
    int x[a+b+1];
    int y[a+b+1];
    for(int i =1 ; i <= a+b; i++)
    {
        if(i > b)
            x[i] = y[i] = 0;
        else
            x[i] = y[i] = 1;
    }

    swap(y[b],y[b+min(a,k)]);
    if(k <= a)
    {
        cy;
        for(int i = 1;  i <= a+b ; i++)   
            cout << x[i];
        cout << endl;
        for(int i = 1 ; i <= a+b ; i++)
            cout << y[i];
    }
    else
    {
        int z = k - a;
        //cout << z << endl;
        int c = b-1;
        while(z--)
        {
            if(c < 0)
                break;
            swap(y[c],y[c+1]);
            c--;
        }
        if(z > 0)
        {
            cn;
            //cout << '!' << endl;
            //cout << z << endl;
        }
        else
        {
            cy;
            for(int i = 1;  i <= a+b ; i++)   
                cout << x[i];
            cout << endl;
            for(int i = 1 ; i <= a+b ; i++)
                cout << y[i];
        }
    }
    
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
