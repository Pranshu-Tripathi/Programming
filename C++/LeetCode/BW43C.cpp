/*
Nahi hua yeh
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        vector <int> ans(2*n+1);
        vector <bool> vis(2*n+1,false);
        vis[0] = true;
        ans[0] = n;
        ans[n] = n;
        for(int i = 1; i < 2 * n +1 ; i++)
        {
            if(!vis[i])
            {
                for( int j = n -1 ; j >= 1 ; j++)
                {
                    if(j != 1)
                    {
                        if(i + j < 2 * n  +1)
                        {
                            if(!vis[i+j])
                                ans[i] = ans[i+j] = j, vis[i] = vis[i+j] = true;
                        }
                    }
                    vis[i] = true;
                    ans[i] = 1;
                }
            }
            return ans;
        }
    }
};