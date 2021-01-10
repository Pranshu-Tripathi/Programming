#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumGain(string s, int x, int y) 
    {
        int sum = 0;
        int n = s.length();
        vector<char> sr, sr2;
        if(x > y)
        {
            for(int i=0;i<n;i++)
            {
                if(s[i] == 'b' && sr.size() != 0 && sr[sr.size()-1] == 'a')
                {
                    sr.pop_back();
                    sum += x;
                }
                else
                {
                    sr.push_back(s[i]);
                }
            }
            for(int i=0;i<sr.size();i++)
            {
                if(sr[i] == 'a' && sr2.size() != 0 && sr2[sr2.size()-1] == 'b')
                {
                    sr2.pop_back();
                    sum += y;
                }
                else
                {
                    sr2.push_back(sr[i]);
                }
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(s[i] == 'a' && sr.size() != 0 && sr[sr.size()-1] == 'b')
                {
                    sr.pop_back();
                    sum += y;
                }
                else
                {
                    sr.push_back(s[i]);
                }
            }
            for(int i=0;i<sr.size();i++)
            {
                if(sr[i] == 'b' && sr2.size() != 0 && sr2[sr2.size()-1] == 'a')
                {
                    sr2.pop_back();
                    sum += x;
                }
                else
                {
                    sr2.push_back(sr[i]);
                }
            }
        }
        return sum;
    }
};