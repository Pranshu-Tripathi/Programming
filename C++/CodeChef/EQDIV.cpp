#include <bits/stdc++.h>
using namespace std;

void display(vector<int> ans){
    for (auto i : ans)
    {

        cout << i ;
    }
    cout << endl;
    return ;
}

int main(){
    int K, test;
    cin >> K >> test;
    while(test--){
        int n;
        cin >> n;
        vector <int> ans(n);
        long long score0 = 0, score1 = 0;
        for(int i = n ; i > 0 ; i--){
            if(i == n){
                score0 += i;
                ans[i-1] = 0;
            }else if(score0 <= score1){
                score0 += i;
                ans[i-1] = 0;
            }else{
                score1 += i;
                ans[i-1] = 1;
            }
        }
        cout << abs(score0 - score1) << endl;
        display(ans); 
    }

}