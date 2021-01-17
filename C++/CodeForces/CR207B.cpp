#include<bits/stdc++.h>
using namespace std;

#define ll long long

void _run()
{
    int n,m;
    cin >> n >> m;
    int arr[n+1];
    memset(arr,-1,sizeof(arr));
    int x,y,z;
    for(int i = 0 ; i < m ; i++)
    {
        cin >> x >> y >> z;
        if(arr[x] == -1 && arr[y] == -1 && arr[z] == -1)
        {
            arr[x] = 1;
            arr[y] = 2;
            arr[z] = 3;
        } 
        else if(arr[x] == -1 && arr[y] == -1)
        {
            // arr[z] is already existing
            switch (arr[z])
            {
            case 1:
                arr[x] = 2;
                arr[y] = 3;
                break;
            case 2:
                arr[x] = 1;
                arr[y] = 3;    
                break;
            case 3:
                arr[x] = 1;
                arr[y] = 2;
                break;
            default: 
                break;
            }
        }
        else if(arr[x] == -1 && arr[z] == -1)
        {
            // arr[y] is already existing
            switch (arr[y])
            {
            case 1:
                arr[x] = 2;
                arr[z] = 3;
                break;
            case 2:
                arr[x] = 1;
                arr[z] = 3;    
                break;
            case 3:
                arr[x] = 1;
                arr[z] = 2;
                break;
            default: 
                break;
            }
        }
        else if(arr[y] == -1 && arr[z] == -1)
        {
            // arr[x] already existing
            switch (arr[x])
            {
            case 1:
                arr[y] = 2;
                arr[z] = 3;
                break;
            case 2:
                arr[y] = 1;
                arr[z] = 3;    
                break;
            case 3:
                arr[y] = 1;
                arr[z] = 2;
                break;
            default: 
                break;
            }
        }
        else if(arr[x] == -1)
        {
            // arr[y] and arr[z] both existing
            if(arr[y] == 1 && arr[z] == 2)
                arr[x] = 3;
            else if(arr[y] == 1 && arr[z] == 3)
                arr[x] = 2;
            else if(arr[y] == 2 && arr[z] == 3)
                arr[x] = 1;
            else if(arr[z] == 1 && arr[y] == 2)
                arr[x] = 3;
            else if(arr[z] == 1 && arr[y] == 3)
                arr[x] = 2;
            else if(arr[z] == 2 && arr[y] == 3)
                arr[x] = 1;
        }
        else if(arr[y] == -1)
        {
            // arr[x] and arr[z] both existing
            if(arr[x] == 1 && arr[z] == 2)
                arr[y] = 3;
            else if(arr[x] == 1 && arr[z] == 3)
                arr[y] = 2;
            else if(arr[x] == 2 && arr[z] == 3)
                arr[y] = 1;
            else if(arr[z] == 1 && arr[x] == 2)
                arr[y] = 3;
            else if(arr[z] == 1 && arr[x] == 3)
                arr[y] = 2;
            else if(arr[z] == 2 && arr[x] == 3)
                arr[y] = 1;
        }
        else if(arr[z] == -1)
        {
            // arr[x] and arr[y] both existing
            if(arr[x] == 1 && arr[y] == 2)
                arr[z] = 3;
            else if(arr[x] == 1 && arr[y] == 3)
                arr[z] = 2;
            else if(arr[x] == 2 && arr[y] == 3)
                arr[z] = 1;
            else if(arr[y] == 1 && arr[x] == 2)
                arr[z] = 3;
            else if(arr[y] == 1 && arr[x] == 3)
                arr[z] = 2;
            else if(arr[y] == 2 && arr[x] == 3)
                arr[z] = 1;
        }
    }
    for(int i = 1 ; i  <= n ; i ++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int test = 1;
    while(test--)
        _run();
    return 0;
}