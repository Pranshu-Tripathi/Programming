#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n,k;
    cin >> n >> k;
    vector <int> weight(n);

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
       
    }

    for (int i = 0; i < n; i++)
    {
         if(weight[i] > k){
             return -1;
        }
    }
    
    int next = 0;
    int sum = 0;
    int trip = 0;

    for(int i = next; i < n;i++){
        sum += weight[i];
        if(sum > k){
            next = i;
            trip++;
            i--;
            sum = 0;
        }
    }
    if(sum != 0){
        trip++;
    }
    return trip;
}



int main(){

    int test;
    cin >> test;

    while(test--){
        cout << solve() << endl;
    }
}