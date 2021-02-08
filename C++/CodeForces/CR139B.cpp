#include<bits/stdc++.h>
using namespace std;
int v[100],kb[100],sum[100];
int main(){
    int s,k;
    int cnt=0;
    cin>>s>>k;
    kb[0]=sum[0]=1;
    int i;

    for(i=1;kb[i-1]<=s;i++)
    {

        kb[i]=sum[i-1]-(i>k?sum[i-k-1]:0);
        sum[i]=sum[i-1]+kb[i];
    }
   // for(int j=1;j<i;j++)cout<<kb[j]<<endl;
    int l=i-1;
    while(s)
    {
        while(s<kb[l])l--;
        s-=kb[l];
        v[++cnt]=kb[l];

        l--;
    }
    if(cnt==1)
    {
        cout<<2<<endl<<0<<' '<<v[cnt];
    }
    else
    {
        cout<<cnt<<endl;
        for(int i=1;i<=cnt;i++)
            cout<<v[i]<<' ';
    }
}

