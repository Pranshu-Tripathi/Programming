#include<bits/stdc++.h>
using namespace std;

const int N = 1000;

long long tree[4 * N] ;
long long lazy[4 * N];
vector<int> arr(N);

void built(int l , int r, int idx)
{
    if(l > r)
        return;
    if(l == r)
    {
        tree[idx] = arr[l];
        return;
    }
    int mid = (l+r)/2;
    built(l,mid,2*idx+1);
    built(mid+1,r,2*idx+2);
    tree[idx] = tree[2*idx+1] + tree[2*idx+2];
}

long long rangeQuery(int l, int r, int ql, int qr, int idx)
{
    if(lazy[idx] != 0)
    {
        tree[idx] += (r-l+1)*lazy[idx];
        if(l != r)
        {
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    // out of range
    if (l>r || l>qr || r<ql)
        return 0;

    // in range 
    if( l >= ql && r <= qr)
    {
        return tree[idx];   
    }

    int mid = (l+r)/2;
    return rangeQuery(l,mid,ql,qr,2*idx+1) 
            + rangeQuery(mid+1,r,ql,qr,2*idx+2);
}

void update(int l, int r, int ql, int qr, int idx, int val)
{
    if(lazy[idx] != 0)
    {
        tree[idx] += (r-l+1)*lazy[idx];
        if(l != r)
        {
            lazy[2*idx+1] += lazy[idx];
            lazy[2*idx+2] += lazy[idx];
        }
        lazy[idx] = 0;
    }

    // out of range
    if (l>r || l>qr || r<ql)
        return ;

    if(l >= ql && r <= qr)
    {
        tree[idx] += (r-l+1)*val;
        if(l != r)
        {
            lazy[2*idx+1] += val;
            lazy[2*idx+2] += val;
        }
        return;
    }

    int mid = (l+r)/2;
    update(l,mid,ql,qr,2*idx+1,val);
    update(mid+1,r,ql,qr,2*idx+2,val);
    tree[idx] = tree[2*idx+1] + tree[2*idx+2];
}


int main()
{
    for(int i = 0 ; i< 10 ; i++)
    {
        cin >> arr[i];
    }
    built(0,9,0);
    cout << rangeQuery(0,9,3,7,0)<< endl;
    update(0,9,3,6,0,1);
    cout << rangeQuery(0,9,3,7,0)<< endl;
}