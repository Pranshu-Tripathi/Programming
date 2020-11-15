#include <bits/stdc++.h>
using namespace std;



void solve(){
    long long k;
    int d1,d0;
    cin >> k >> d0 >> d1;
    int digit_3 = (d0+d1) % 10;
    if(digit_3 == 0){
        cout << "N0" << endl;
        return;
    }
    int possible_digit[4] = {4,8,6,2};
    long long sum1 = (k-3)/4;
    sum1*=((2*(d0+d1))%10 + (4*(d1+d0)) % 10 + (6*(d0+d1)%10) + (8*(d1+d0))%10);

    int digit_4 = (d0+d1+digit_3)%10;
    int loop = (k-3) % 4;

    int start;
    for(int i = 0 ; i < 4 ; i++){
        if(digit_4 == possible_digit[i]){
            start = i;
            break;
        }
    }
    long long sum2 = 0;
    while(loop--){
        sum2+= possible_digit[start];
        start = (start+1)%4;
    }

    long long final_sum = d0+d1+digit_3+sum1+sum2;

    if(final_sum%3 == 0){
        cout << "YES" <<endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}