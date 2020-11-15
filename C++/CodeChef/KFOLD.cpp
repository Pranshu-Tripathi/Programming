#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k;
    cin >> n >> k;

    char inp;
    vector <int> freq01(2,0);
    for (int i = 0; i < n; i++)
    {
        cin >> inp;
        freq01[inp-'0']++;
    }

    int factor = n / k;
    bool possible = false;

    for(int i = 0; i <= k ; i++){
        int fre0 = factor *(k-i);
        int fre1 = factor*i;

        if(fre0 == freq01[0] && fre1 == freq01[1]){
            possible = true;
            break;
        }
    }
    
    if(possible){
        int zps = freq01[0]/factor;
        int ops = freq01[1]/factor;

        string s1(zps,'0');
        string s2(ops,'1');

        string str_part1 = "";
        string str_part2 = "";

        str_part1 += s1;
        str_part1 += s2;
        str_part2 += s2;
        str_part2 += s1;
        // made the 2k string part

        string answer ="";
        bool part1_add = true;
        for(int i= 0 ; i < factor ;i ++){
            if(part1_add){
                answer += str_part1;
                part1_add = false;
            }else{
                
                answer += str_part2;
                part1_add = true;
            }
        }

        cout << answer << endl;
    }else{
        cout << "IMPOSSIBLE" <<endl;
    }
}


int main(){
    int test;
    cin >> test;
    while(test--){
        solve();
    }
}