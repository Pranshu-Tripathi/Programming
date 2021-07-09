/*
Given a number of piles in which each pile contains some numbers of stones/coins. 
In each turn, a player can choose only one pile and remove any number of stones (at least one) from that pile. 
The player who cannot move is considered to lose the game (i.e., one who take the last stone is the winner).*/

/*
“If both A and B play optimally (i.e- they don’t make any mistakes), 
then the player starting first is guaranteed to win if the Nim-Sum at the beginning of the game is non-zero. 
Otherwise, if the Nim-Sum evaluates to zero, then player A will lose definitely.”
*/

// nim -sum at any point is xor of the values


#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0 ; i < n ; i++)
        cin >> arr[i];
    
    int x = 0;
    for(int i = 0 ; i < n ; i++)
        x ^= arr[i];
    
    if(x)
        cout << 1 << endl;
    else
        cout << 2 << endl;
}
