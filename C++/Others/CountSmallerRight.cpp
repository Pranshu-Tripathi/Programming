#include<iostream>
#include<vector>
#include<set>
#include<unordered_map>
#define MAXN 1000005
using namespace std;


class Solution {
public:
    int bit[MAXN];
    int n;
    unordered_map<int,int> mp;
    void update(int i, int val)
    {
        for(; i <= n ; i += (i&-i))
        {
            bit[i] += val;
        }
    }
    int query(int i)
    {
        int sum = 0;
        for(; i > 0 ; i -= (i&-i))
        {
            sum += bit[i];
        }
        return sum;
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size());
        int rank = 0;
        set<int> st(nums.begin(),nums.end());
        for(auto it : st)
            mp[it] = ++rank;
        n = rank + 1;

        for(int i = nums.size() - 1 ; i >= 0 ; i--)
        {
            ans[i] = query(mp[nums[i]] - 1);
            update(mp[nums[i]],1);
        }
        return ans;
    }
};