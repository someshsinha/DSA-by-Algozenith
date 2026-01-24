/*
stuff to do 
the question is that there is a 2d array and in that you have to find the max path sum from (1,1) to (n,m)
if only downward and forward move are allowed

2 3 5 1
9 1 10 11
5 6 3 2
1 11 5 3
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>board;
vector<vector<int>>dp;
int rec(int r,int c)
{
    //pruning
    if(r<0 || c<0)return INT_MIN;
    //base case
    if(r==0 && c==0)return board[0][0];
    //cache check
    if(dp[r][c]!=-1)return dp[r][c];
    //transition
    int ans=0;
    if(r!=0)ans=max(ans,board[r][c]+rec(r-1,c)); 
    if(c!=0)ans=max(ans,board[r][c]+rec(r,c-1));
    //save and return
    dp[r][c]=ans;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    board.assign(n,vector<int>(n));
    dp.assign(n,vector<int>(n,-1));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>board[i][j];
        }
    }
    cout<<rec(n-1,n-1)<<endl;
    return 0;
}
