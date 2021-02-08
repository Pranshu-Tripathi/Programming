#include<bits/stdc++.h>
using namespace std;

int c ;

void dfs(long long num, long long limit)
{
    if(num >= 1 && num <= limit)
        c++;
    else
    {
        return;
    }
    
    long long n1 = num * 10 + 0;
    long long n2 = num * 10 + 1;

    dfs(n1,limit);
    dfs(n2,limit);
    
    return;
}

int main()
{
    long long n;
    cin >> n;

    dfs(1,n);
    cout << c<< endl;    

}