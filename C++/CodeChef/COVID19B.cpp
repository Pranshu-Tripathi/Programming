#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector <int> sp(n+1);
    for (int i = 1; i <= n; i++){
        cin >> sp[i];
    }

    set <int> infected;
    vector <int> answer(n+1);
    answer[0] = -1;
    int M = 1;
    int m = 1000;
    for(int source = 1 ; source <= n ; source++){
        infected.insert(source);
        for(int i = 1 ; i <=n ; i++){
            if(i == source){
                continue;
            }else if(i < source){
                if(sp[i] > sp[source]){
                    infected.insert(i);
                    for(int j = source+1 ; j <= n ; j++){
                        if(sp[j] >= sp[source] && sp[j] < sp[i]){
                            infected.insert(j);
                        }
                    }
                }
            }else{
                if(sp[i] < sp[source]){
                    infected.insert(i);
                    for(int j = 1 ; j < source ; j++){
                        if(sp[j] > sp[i] && sp[j] <= sp[source]){
                            infected.insert(j);
                        }
                    }
                }
            }
        }
        answer[source] = infected.size();
        infected.clear();
    }

    sort(answer.begin() , answer.end());
    cout << answer[1] << " " << answer[answer.size() - 1] << endl;

}

int main(){
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}