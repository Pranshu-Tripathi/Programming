#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)


map<char,int> digitRep;

void digitMapping()
{
    digitRep['1'] = 1;
    digitRep['2'] = 2;
    digitRep['3'] = 3;
    digitRep['4'] = 4;
    digitRep['5'] = 5;
    digitRep['6'] = 6;
    digitRep['7'] = 7;
    digitRep['8'] = 8;
    digitRep['9'] = 9;
    digitRep['A'] = 10;
    digitRep['B'] = 11;
    digitRep['C'] = 12;
    digitRep['D'] = 13;
    digitRep['E'] = 14;
    digitRep['F'] = 15;
    digitRep['G'] = 16;
    digitRep['H'] = 17;
    digitRep['I'] = 18;
    digitRep['J'] = 19;
    digitRep['K'] = 20;
    digitRep['L'] = 21;
    digitRep['M'] = 22;
    digitRep['N'] = 23;
    digitRep['O'] = 24;
    digitRep['P'] = 25;
    digitRep['Q'] = 26;
    digitRep['R'] = 27;
    digitRep['S'] = 28;
    digitRep['T'] = 29;
    digitRep['U'] = 30;
    digitRep['V'] = 31;
    digitRep['W'] = 32;
    digitRep['X'] = 33;
    digitRep['Y'] = 34;
    digitRep['Z'] = 35;
}

int getMinBase(char c)
{
    return digitRep[c] + 1;
}

void _run()
{

    digitMapping();
    
    string mClock;
    cin >> mClock;
    //cout << mClock;
    int minBase = 0;
    bool minusOne = true;
    int i;
    vector<int> hour;
    vector<int> min;

    for(i = 0 ; mClock[i] != ':' ; i++)
    {   
        // if(mClock[i] == ' ')
        //     continue;
        minBase = max(minBase,getMinBase(mClock[i]));
        if(mClock[i] != '0' && (mClock[i+1] != ':' ))
            minusOne = false;
        hour.push_back(digitRep[mClock[i]]);
    }


    if(digitRep[mClock[i-1]] > 23)
        minusOne = false;
    

    for(int j = i + 1 ; j  < mClock.length() ; j++)
    {
        // if(mClock[j] == ' ')
        //     continue;
        minBase = max(minBase,getMinBase(mClock[j]));
        if(mClock[j] != '0' && j != mClock.length() -1)
            minusOne = false;
        min.push_back(digitRep[mClock[j]]);
    }

    if(minusOne)
    {
        cout << -1 << endl;
        return;
    }


    set<int> answerBase;

    for(int base = minBase ; base <= 59 ; base++)
    {
        ll anshr = 0, ansmi = 0;
        for(int hi = hour.size() - 1 ; hi >= 0 ; hi--)
        {   
            anshr += hour[hi] * pow(base,hour.size() - 1 - hi);
        }
        if(anshr <= 23)
        {
            for(int mi = min.size() - 1 ; mi >= 0 ; mi--)
            {
                ansmi += min[mi] * pow(base,min.size() - 1  - mi);
            }
            if(ansmi <= 59)
                answerBase.insert(base);
        }
        // cout << base << ' '<<  anshr << ' ' << ansmi << endl;
    }
    if(answerBase.empty())
    {
        cout << 0 << endl;
        return;
    }

    for(auto b : answerBase)
        cout << b << ' ';
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
