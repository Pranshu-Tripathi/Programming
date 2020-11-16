/*

You are lost in a dense jungle and it is getting dark. 
There is at least one path that leads you to the city on the other side but you cannot see anything until you are right in front of it as the trees and bushes obscure the path.

Devise an algorithm that is guaranteed to find the way out. 
Your goal is to go out of the jungle as fast as you can before it gets dark.

[Input]:
Input start with a number N and then the matrix of size N x N filled with S, E, T, and P which is our map.
Map contains a single S representing the start point, and single E representing the end point and P representing the path and T representing the Tree.

[Output]:
output single integer i.e. minimum number of moves from S to E.

Assumptions:
You can assume that the maps would be in square form and can be up to a maximum size of 30X30. 
You can move in four directions North East West South.
You can move in any direction when you find P but cannot move to a point where a T is present.

*Problem provided by JDA

Hackerearth Problem.

*/

#include<bits/stdc++.h>
using namespace std;

char grid[31][31];
int dist[31][31];
bool vis[31][31];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};

bool isValid(int x, int y, int n)
{
    if(x > n || y > n || x < 1 || y < 1)
        return false; 
    if(vis[x][y] || grid[x][y] == 'T')
        return false;
    return true;
}

void bfs(int x, int y, int n)
{
    dist[x][y] = 0;
    vis[x][y] = true;
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty())
    {
        int currX = q.front().first;
        int currY = q.front().second;
        q.pop();
        for(int i = 0 ; i < 4; i++)
            if(isValid(currX+dx[i],currY+dy[i],n))
            {
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                vis[newX][newY] = true;
                dist[newX][newY] = dist[currX][currY] + 1;
                q.push({newX,newY});
            }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    pair<int,int> Start, End;
    for(int i = 1 ; i <= n; i++)
        for(int j = 1 ; j <= n ; j++)
        {
            cin >> grid[i][j];
            if(grid[i][j] == 'S')
                Start.first = i, Start.second = j;
            if(grid[i][j] == 'E')
                End.first = i, End.second = j;
        }
    bfs(Start.first,Start.second,n);
    cout << dist[End.first][End.second];
}