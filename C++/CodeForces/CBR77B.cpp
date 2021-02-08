#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)



set<ll> superLucky;

int getsevenCount(ll n)
{
    int sev = 0;
    while(n)
    {
        if(n%10 == 7)
            sev++;
        n/=10;
    }
    return sev;
}

bool isLucky(ll n)
{
    while(n)
    {
        if(n%10 != 4 && n % 10 != 7)
            return false;
        n /= 10;
    }
    return true;
}

int getfourCount(ll n)
{
    int fou = 0;
    while(n)
    {
        if(n%10 == 4)
            fou++;
        n/=10;
    }
    return fou;
}


int getSize(ll n)
{
    int dig = 0;
    while(n)
    {
        dig++;
        n/=10;
    }
    return dig;
}

void genLucky(ll option1, ll sizeLimit)
{

    //cout << option1 << ' ' << isLucky(option1) <<endl;
    if(getSize(option1) < sizeLimit)
    {
        ll op1 = option1*10+4;
        ll op2 = option1*10+7;
        if(getsevenCount(op1) == getfourCount(op1) && isLucky(op1))
            superLucky.insert(op1);
        if(getsevenCount(op2) == getfourCount(op2) && isLucky(op2))
            superLucky.insert(op2);
        genLucky(op1,sizeLimit);
        genLucky(op2,sizeLimit);
    }


    return;
}

void _run()
{
    ll n;
    cin >> n;
    superLucky.clear();
    genLucky(4,10);
    genLucky(7,10);
    vector<ll> suuperLuck;
    for(long long x : superLucky)
    {
        suuperLuck.push_back(x);
    }
    int l = 0;
    int r = suuperLuck.size() - 1;
    while(l < r)
    {
        int mid = l + (r-l)/2;
        if(suuperLuck[mid] < n)
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    cout << suuperLuck[r] << endl; 
}

int main()
{
    fast;
    int test=1;
    
    while(test--)
        _run();
    return 0;
}
