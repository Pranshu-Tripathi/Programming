#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast  ios::sync_with_stdio(false); \
    cin.tie(NULL)

// [friends][0] - taxi
// [friends][1] - pizza
// [friends][2] - girls

const string taxicalls = "If you want to call a taxi, you should call: ";
const string pizzacalls = "If you want to order a pizza, you should call: ";
const string girlcalls = "If you want to go to a cafe with a wonderful girl, you should call: ";

void convertVector(vector<int> & nums, string str)
{
    for(int i = 0 ; i < str.length() ; i++)
    {
        if(str[i] == '-')
            continue;
        else
            nums.push_back(str[i] - '0');
    }
}

bool isTaxi(vector<int>& nums)
{
    bool x = true;
    for(int i = 1 ; i < nums.size() ; i++)
        if(nums[i] != nums[i-1])
            x = false;
    
    return x;
}

bool isPizza(vector<int>& nums)
{
    bool x = true;
    for(int i = 1 ; i < nums.size() ; i++)
        if(nums[i] >= nums[i-1])
            x = false;

    return x;
}

void _run()
{
    int friends;
    cin >> friends;
    int a[friends][3];
    int mxTaxi = 0 , mxPizza = 0 , mxGirls = 0;
    memset(a,0,sizeof(a));
    vector<string> names(friends);
    for(int i = 0 ; i < friends ; i++)
    {
        int pnos;
        cin >> pnos;
        cin >> names[i];
        for(int j = 0;  j < pnos ; j++)
        {
            string num;
            cin >> num;
            vector<int> nums;
            convertVector(nums,num);
            if(isTaxi(nums))
            {
                a[i][0]++;
            }
            else if(isPizza(nums))
            {
                a[i][1]++;
            }
        }
        a[i][2] = pnos - a[i][0] - a[i][1];
        mxTaxi = max(mxTaxi,a[i][0]);
        mxPizza = max(mxPizza,a[i][1]);
        mxGirls =  max(mxGirls,a[i][2]);
    }

    cout << taxicalls;

    vector<string> taxi;
    for(int i = 0 ; i < friends ; i++)
        if(mxTaxi == a[i][0])
            taxi.push_back(names[i]);
    
    for(int i = 0 ; i < taxi.size() ; i++)
    {
        if(i != taxi.size() - 1)
        {
            cout << taxi[i] << ", ";
        }
        else
        {
            cout << taxi[i] << ".";
        }
    }

    cout << endl;

    cout << pizzacalls;

    vector<string> pizza;
    for(int i = 0 ; i < friends ; i++)
        if(mxPizza == a[i][1])
            pizza.push_back(names[i]);

    for(int i = 0 ; i < pizza.size() ; i++)
    {
        if(i != pizza.size() - 1)
        {
            cout << pizza[i] << ", ";
        }
        else
        {
            cout << pizza[i] << ".";
        }
    }

    cout << endl;

    cout << girlcalls;

    vector<string> girl;
    for(int i = 0 ; i < friends ; i++)
        if(mxGirls == a[i][2])
            girl.push_back(names[i]);

    for(int i = 0 ; i < girl.size() ; i++)
    {
        if(i != girl.size() - 1)
        {
            cout << girl[i] << ", ";
        }
        else
        {
            cout << girl[i] << ".";
        }
    }

    cout << endl;
}

int main()
{
    fast;
    int test=1;
    while(test--)
        _run();
    return 0;
}
