/*Problem Statement: Given a rod of length $n$ and an array prices[] where prices[i] represents the selling price of a rod of length $i+1$, determine the maximum profit obtainable by cutting up the rod and selling the pieces. You may cut the rod into as many pieces as required.
*/
#include<bits/stdc++.h>
using namespace std;
/*
Main idea:
forget about everything and dp[l][r]=find the best way to cut a rod from L to R
dp[l][r]=max(xr-xl)+dp[l][p]+dp[p][r];
*/
vector<vector<int>>dp;
vector<int>a;
int var(int l,int r)
{
    //pruning
    if(l>r)return 0;
    //base case
    if(r==1+1)return 0;
    //cache check
    if(dp[l][r]!=-1)return dp[l][r];
    //transition
    dp[l][r]=1e9;
    for(int i=l+1;i<r;i++)
    {
        dp[l][r]=min(dp[l][r],var(l,i)+var(i,r)+(a[r]-a[l]));
    }
    //save the answer and return
    return dp[l][r];
}
int main()
{
    int n;
    cin>>n;
    a.assign(n+1,0);
    dp.assign(n+1,vector<int>(n+1,-1));
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=dp[1][n];
    cout<<ans<<endl;
    return 0;
}
/*
please correct this code
*/