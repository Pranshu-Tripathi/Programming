#include <bits/stdc++.h>
using namespace std;

#define m 1000000007
vector <long long> factorials(100001,1);
long long power(long long int a ,int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    if(b%2 == 0){
        long long int ret = power(a,b/2);
        ret =  ((ret%m )*(ret%m))%m;
        return ret;
    }
    else{
        long long int ret = power(a,b/2);
        ret = ((ret%m) * (ret%m))%m;
        ret = ((ret%m)*(a%m))%m;
        return ret;
    }
}

void factorial(){
    for(int i = 2 ; i <= 100000 ; i++ ){
        factorials[i] = (i % m * factorials[i-1] % m) % m;
    }
}

long long inverse(long long x){
    return ((long long)power(x,m-2) % m);
}

void solve(){
    int n;
    cin >> n;
   
    int fre = 0;
    vector<long long> cards_value(n);

    for(int i = 0 ; i < n ; i++){
        cin >> cards_value[i];
    }

    sort(cards_value.begin(),cards_value.end(),greater<int>());

    for(int i = 0 ; i < n ; i++){
        if(cards_value[i] == cards_value[0]){
            fre++;
        }
    }
    //cout << "Fre : " << fre <<endl;
    long long total  = power(2,n);

    //cout << "Total : " << total << endl;
     
    if(fre % 2 == 0){
        long long left = power(2,n-fre);
        //cout << "Lef : " << left << endl;
        long long frefact = factorials[fre];
        long long deno = (factorials[fre/2]%m) * (factorials[fre/2] % m) % m;
        long long fre_dis = ((frefact % m) * inverse(deno) %m)%m;
        long long cases_draw =  ((left % m) * (fre_dis%m))%m;
        //cout << "Fre fac : " << frefact << endl;
       //cout << "Deno : " << deno << endl;
        
        //cout << "Dis : " <<fre_dis << endl;
        //cout  << cases_draw << endl;
        long long cases_win = ((total%m)+m-(cases_draw%m))%m;

        cout << cases_win <<endl; 
    }else{
        cout << total << endl;
    }

}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    factorial();
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}