#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

void _run()
{
    int n;
    cin >> n;
    vector<int> digits(n);
    int sumdig = 0;
    for(int i = 0 ; i < n ; i ++)
        cin >> digits[i], sumdig += digits[i];
    sort(digits.begin(),digits.end());
    vector<int> modl(n);
    int mod1= 0, mod2 = 0;
    for(int i = 0 ; i < n ; i ++)
    {
        modl[i] = digits[i] % 3;
        if(modl[i] == 1) mod1++;
        if(modl[i] == 2) mod2++;
    }
    if(digits[0] != 0)
    {
        cout << -1 << endl;
        return;
    }

    if(sumdig == 0)
    {
        cout << 0;
        return;
    }

    if(sumdig % 3 == 0)
    {
        for(int i = n -1 ; i >= 0 ; i--)
        {
            cout << digits[i];
        }
        return;
    }

    else if(sumdig % 3 == 1)
    {
        if(mod1 != 0)
        {
            for(int i = 0 ; i < n ; i ++)
            {
                if(modl[i] == 1)
                {
                    digits[i] = -1;
                    break;
                }
            }
        }
        else if(mod2  >= 2)
        {
            int cnt = 0;
            for(int i = 0 ; i < n ; i++)
            {
                if(cnt == 2)
                    break;
                if(modl[i] == 2)
                {
                    digits[i] = -1;
                    cnt++;
                }
            }
        }
    }

    else
    {
            if(mod2 != 0)
            {
                for(int i = 0 ; i < n ; i ++)
                {
                    if(modl[i] == 2)
                    {
                        digits[i] = -1;
                        break;
                    }
                }
            }
            else if(mod1  >= 2)
            {
                int cnt = 0;
                for(int i = 0 ; i < n ; i++)
                {
                    if(cnt == 2)
                        break;
                    if(modl[i] == 1)
                    {
                        digits[i] = -1;
                        cnt++;
                    }
                }
            }
    }
    bool allzero = true;
    {
        for(int i = n-1 ; i >= 0; --i)
        {
            if(digits[i] != -1)
            {
                if(digits[i] != 0)
                    allzero = false;
            }
        }
    }
    if(allzero)
    {
        cout << 0;
    }
    else
    {
        for(int i = n - 1 ;i >= 0 ; i--)
        {
            if(digits[i] != -1)
                cout << digits[i];
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
