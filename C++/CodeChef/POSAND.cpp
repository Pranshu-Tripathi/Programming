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

vector<int> powers;

int expo(int A,int B)
{
    if(A == 1 || B == 0)  return 1;
    if(B == 1)  return A;
    if(B%2 == 0)
    {
        int ret = expo(A,B/2);
        ret*=ret;
        return ret;
    }
    else
    {
        int ret = expo(A,B/2);
        ret*=ret;
        ret*=A;
        return ret;
    }   
}

bool check(int x)
{
    FORE(i,1,20)
    {
        if(x == powers[i])
        return true;
    }
    return false;
}

void task()
{
    int bf[6] = {-1,2,3,1,5,4}; 
    int n,i;
    cin >> n;

    if(n==1)
    {
        cout << 1 << endl;
        return;
    }
    FOR(i,0,20)
    {
        if(n == powers[i])
        {
            cout << -1 << endl;
            return;
        }
    }
    
    if(n <= 5)
    {
        FORE(i,1,n)
        {
            cout << bf[i] << " "; 
        }
        cout << endl;
    }
    else
    {
        vector<int> ans;
        vector<int> index;
        FORE(i,1,n)
        {
            if(i <=5)
            {
                cout << bf[i] << " "; 
            }
            else
            {
                if(check(i))
                {
                    index.pb(i-6);
                }

                ans.pb(i);
            }
            
        }
    
        FOR(i,0,index.size())
        {
            swap(ans[index[i]],ans[index[i]+1]);
        }
        FOR(i,0,ans.size())
        {
            cout << ans[i] << " ";
        }   

        cout << endl;

    }
    
}

int main()
{
    int test,i;
    cin >> test;
    FORE(i,1,20)
    {
        powers.pb(expo(2,i));
    }
    while(test--)
    {
        task();
    }
}