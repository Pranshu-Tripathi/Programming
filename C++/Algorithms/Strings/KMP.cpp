#include<bits/stdc++.h>
using namespace std;

int cunt = 0;

void compute_L_P_S_Array(string& par, int m,int * lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while(i < m)
    {
        if(par[i] == par[len])
            len++,lps[i]= len,i++;
        else
        {
            if(len != 0)
                len = lps[len-1];
            else
                lps[i] = 0,i++;
        }
    }
}


void _K_M_P_Search(string & text, string & par)
{
    int m = par.length();
    int n = text.length();
    int lps[m];
    compute_L_P_S_Array(par,m,lps);
    int i = 0 ; 
    int j = 0;
    while(i < n)
    {
        if(par[j] == text[i])
            i++,j++;
        if(j == m)
            cunt++,j = lps[m-1];
        else if(i < n && par[j] != text[i])
        {
            if(j != 0)
                j = lps[j-1];
            else
                i += 1;
        }
    }


}

int main()
{
    string text,pat;
    cin >> text >> pat;
    int count = 0;
    _K_M_P_Search(text,pat);
    cout << cunt << endl;
}