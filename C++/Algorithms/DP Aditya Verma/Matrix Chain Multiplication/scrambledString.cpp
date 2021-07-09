#include<bits/stdc++.h>
using namespace std;

bool scramblers(string a, string b)
{
    if(a.compare(b) == 0)
        return true;
    
    if(a.length() <= 1)
        return false;
    int n = a.length();
    bool flag = false;
    for(int i = 1 ; i < n ; i++)
    {
        bool con1 = scramblers(a.substr(0,i),b.substr(0,i));
        bool con2 = scramblers(a.substr(i),b.substr(i));
        if(con1 and con2)
        {
            flag = true;
            break; 
        }
        
        bool con3 = scramblers(a.substr(0,i),b.substr(n-i));
        bool con4 = scramblers(a.substr(i),b.substr(0,n-i));
        if(con3 and con4)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

unordered_map<string,int> mp;
bool memo(string a, string b)
{
    if(a.compare(b) == 0)
        return true;
    if(a.length() <= 1)
        return false;

    if(mp.find(a + ' ' + b) != mp.end())
        return mp[a+' ' + b];
    
    int n = a.length();
    for(int i = 1 ; i < n ; i++)
    {
        bool withoutswap = (
                memo(a.substr(0,i),b.substr(0,i)) 
                &&
                memo(a.substr(i),b.substr(i))
                );
            
            if(withoutswap)
                return mp[a+' '+b] = true;
            
            bool withswap = (
                memo(a.substr(0,i),b.substr(n-i)) 
                &&
                memo(a.substr(i),b.substr(0,n-i)) 
                );
            
            if(withswap)
                return mp[a+' '+b] = true;
    }
    return mp[a+ ' ' + b] = false;

}

int main()
{
    string a,b;
    cin >> a >> b;
    cout << scramblers(a,b) << endl;
    cout << memo(a,b);
}