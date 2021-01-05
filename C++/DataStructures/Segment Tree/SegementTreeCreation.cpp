#include<bits/stdc++.h>
using namespace std;

void _build(vector<int>& arr, vector<int> & st, int ss, int se, int si)
{
    if(ss == se)
    {
        st[si] = arr[ss];
        return;
    }

    int mid = ss + (se - ss) / 2;

    _build(arr,st,ss,mid,2*si+1);
    _build(arr,st,mid+1,se,2*si+2);

    st[si] = st[2 * si + 1] + st[2 * si + 2];

    return;
}

int _rangeQuery(int qs,int qe, int ss, int se, int si, vector<int>& st)
{
    if(qs <= ss && qe >= se)
    {
        return st[si];
    }

    if(qe < ss || qs > se)
    {
        return 0;
    }

    int mid = (ss+se)/2;

    return _rangeQuery(qs,qe,ss,mid,si * 2 + 1 , st) + _rangeQuery(qs,qe,mid+1,se,si * 2 + 2, st);
}

void _update(vector<int>& st, int ss, int se,int val ,int idx, int stIdx)
{
    if(ss == se)
    {
        st[stIdx] = val;
        return;
    }

    int mid = (ss + se)/2;

    if(idx > ss)
        _update(st,mid+1,se,val,idx,2*stIdx+2);
    else
        _update(st,ss,mid,val,idx,2*stIdx+1);
    
    st[stIdx] = st[stIdx*2+1] + st[stIdx*2+2];
    return;
}

int main()
{
    ios::sync_with_stdio(false),
    cin.tie(NULL);

    vector<int> arr = {1,3,5,7,9,11};

    int n = arr.size();

    vector<int> st(4*n,-1);


    _build(arr,st,0,n-1,0);

    for(auto x : st)
    {
        if(x == -1)
        {
            cout << "NC "; 
            continue;
        }
        cout << x << " ";
    }

    cout <<endl<<_rangeQuery(1,4,0,n-1,0,st);

}