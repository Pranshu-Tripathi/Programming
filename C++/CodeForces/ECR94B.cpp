#include <bits/stdc++.h>
using namespace std;

int follower(int num_sw,int num_ax,long long wei_sw,long long wei_ax,long long fol_pow){

    if(num_sw > num_ax){
        return follower(num_ax,num_sw,wei_ax,wei_sw,fol_pow);
    }
    if(wei_sw*num_sw  >= fol_pow){
        return fol_pow/wei_sw;
    }

    return num_sw+min((fol_pow-(num_sw*wei_sw))/wei_ax,(long long)num_ax);
}


int solve(){
    long long my_pow,fol_pow;
    cin >> my_pow >> fol_pow;

    int num_sw,num_ax;
    cin >> num_sw >> num_ax;

    long long wei_sw,wei_ax;
    cin >> wei_sw >> wei_ax;

    int ans = 0;

     for(int num_sw_me = 0; num_sw_me <= num_sw;num_sw_me++){
         int num_ax_me = (my_pow - num_sw_me*wei_sw)/wei_ax;
         ans = max(ans,num_sw_me+num_ax_me+follower(num_sw-num_sw_me,num_ax-num_ax_me,wei_sw,wei_ax,fol_pow));
     }

    return ans;
}


int main(){
    int test;
    cin >> test;
    while(test--){
        cout << solve() << endl;
    }
}