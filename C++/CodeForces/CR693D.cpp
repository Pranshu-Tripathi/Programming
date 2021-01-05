#include<bits/stdc++.h>
using namespace std;

string alice = "Alice";
string bob = "Bob";
string tie  = "Tie";

void _run()
{
    int n;
    cin >> n;
    vector<long long> arr(n);
    vector<long long> even;
    vector<long long> odd;

    for(int i = 0 ;  i < n ; i++)
    {
        cin >> arr[i];
        if(arr[i] % 2 == 0)
            even.push_back(arr[i]);
        else
            odd.push_back(arr[i]);
    }

    sort(even.begin(),even.end(), greater<long long>());
    sort(odd.begin(),odd.end(),greater<long long>());

    int evenMax= 0;
    int oddMax = 0;

    long long al = 0;
    long long bo = 0;

    al += even[evenMax];
    evenMax++;

    bool b = true;
    while(evenMax != even.size() || oddMax != odd.size())
    {
        if(b)
        {
            // bobs turn
            if(al > bo)
            {
                if(oddMax == odd.size())
                {
                    cout << alice << endl;
                    return;
                }
                bo += odd[oddMax];
                oddMax++;
            }
            else
            {
                if(evenMax == even.size())
                {
                    cout << bob << endl;
                    return;
                }
                
                if(bo < even[evenMax] + al || odd.size() == oddMax)
                {
                    evenMax ++;
                }
                else
                {
                    bo += odd[oddMax];
                    oddMax++;
                }
            }
            b = !b;
        }
        else
        {
            // alice turn
            if(al > bo)
            {
                if(oddMax == odd.size())
                {
                    cout << alice << endl;
                }

            }
        }
        
    }

}

int main()
{
    int test;
    cin >> test;
    while(test--)
        _run();
    return 0;
}