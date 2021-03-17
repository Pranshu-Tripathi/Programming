#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL),\
    cout.tie(NULL)
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl

int convertDecimal(vector<int>& vec)
{
    int tim = 0;
    tim += vec[0] * 10;
    tim += vec[1];
    return tim;
}

int convertTimeMinutes(int hr, int min)
{
    return hr * 60 + min;
}

void _run()
{
    
    string s1,s2,s3,s4;
    cin >> s1 >> s2;
    vector<int> hrs_meeting,min_meeting;
    int hrm,mim;                
    int i;
    for(i = 0 ; s1[i] != ':' ;i++)
    {
        hrs_meeting.push_back(s1[i] - '0');
    }
    hrm = convertDecimal(hrs_meeting);
    if(s2[0] == 'A')
    {
        if(hrm == 12)
            hrm = 0;
    }
    else if(s2[0] == 'P')
    {
        if(hrm < 12)
            hrm += 12;
    }
    for( i = i  +1 ; i < s1.length() ; i++)
    {
        min_meeting.push_back(s1[i] - '0');
    }
    mim = convertDecimal(min_meeting);
    int meetMins = convertTimeMinutes(hrm,mim);
    int q;
    cin  >> q;
    vector<int> ans;
    while(q--)
    {
        cin >> s1 >> s2 >> s3 >> s4;
        vector<int> hrs_person,min_person;
        int pos;
        for(pos =0 ; s1[pos] != ':' ;pos++)
        {
            hrs_person.push_back(s1[pos] - '0');
        }
        int hrpl,mipl,hrpr,mipr;
        hrpl = convertDecimal(hrs_person);
        if(s2[0] == 'A')
        {
            if(hrpl == 12)
                hrpl = 0;
        }
        else if(s2[0] == 'P')
        {   
            if(hrpl < 12)
                hrpl += 12;
        }
        for(pos = pos + 1 ; pos < s1.length() ; pos++)
        {
            min_person.push_back(s1[pos] - '0');
        }
        mipl = convertDecimal(min_person);
        int time1 = convertTimeMinutes(hrpl,mipl);
        hrs_person.clear(),min_person.clear();

        for(pos =0 ; s3[pos] != ':' ;pos++)
        {
            hrs_person.push_back(s3[pos] - '0');
        }
        hrpr = convertDecimal(hrs_person);
        if(s4[0] == 'A')
        {
            if(hrpr == 12)
                hrpr = 0;
        }
        else if(s4[0] == 'P')
        {   
            if(hrpr < 12)
                hrpr += 12;
        }
        for(pos = pos + 1 ; pos < s3.length() ; pos++)
        {
            min_person.push_back(s3[pos] - '0');
        }
        mipr = convertDecimal(min_person);
        int time2 = convertTimeMinutes(hrpr,mipr);
        if(time1 > time2)
            swap(time1,time2);
        if(meetMins <= time2 && meetMins >= time1)
        {
            ans.push_back(1);
        }
        else
        {
            ans.push_back(0);
        }
    }

    for(int i = 0 ; i < ans.size() ;i++)
    {
        cout << ans[i];
    }

    cout << endl;

}

int main()
{
    fast;
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}
