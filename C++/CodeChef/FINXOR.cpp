#include <bits/stdc++.h>
using namespace std;

int printAns(long long ans){
    int check;
    cout << 2 << " " << ans << endl;
    cin >> check;
    return check;
}

void askQuestion(int x){
    cout << 1 << " " << x << endl;
}

int solve(){
    int n;
    cin >> n;
    vector <int> K(20);
    K[0] = 1;
    for(int i = 1 ; i < 20 ; i++){
        K[i] = K[i-1]*2;
    }

    vector <int> grader_values(20);
    vector <int> coefficients(20);
    long long sum_graders = 0;

    for(int i = 0 ; i < 20 ; i++){
        askQuestion(K[i]);
        cin >> grader_values[i];
        sum_graders += grader_values[i];
    }

    long long summation_equation = (sum_graders - (pow(2, 20) - 1) * n)/18;
    long long  answer = 0;
    for(int i = 0 ; i < 20 ; i++){
        coefficients[i] = (n +( (summation_equation - grader_values[i]) / K[i])) /2;
        if(coefficients[i] % 2 == 0){
            coefficients[i] = 0;
        }else{
            coefficients[i] = 1;
        }
    }

    for(int i = 19 ; i >=0 ;i --){
        answer+= K[i]*coefficients[i];
    }

    int state = printAns(answer);
    return state;
}

int main(){
    int test;
    cin >> test;

    while(test-- ){
       int state = solve();
       if(state == -1){
           break;
       }
    }
}