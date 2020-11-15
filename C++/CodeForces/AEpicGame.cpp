#include<bits/stdc++.h>
using namespace std;

int main(){

    int a,b,n;
    cin >> a >> b >>n;

    bool simon = true;
    bool sim_turn = true;

    while(n > 0){
        if(sim_turn){
            n = n - (__gcd(a,n));
            sim_turn = false;
            if(n <= 0){
                simon = true;
            }
        }else{
            n = n - (__gcd(b,n));
            sim_turn = true;
            if(n <=0){
                simon = false;
            }
        }
    }

    if(simon){
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
    }

}