// Leetcode-312(Burst Balloons problem)
#include<bits/stdc++.h>
using namespace std;
/*
approach in range l to r at last I burst the balloon k 
so my dp state will be
dp[l][r]=max(dp[l][k-1]+dp[k-1][r]+a[k]*a[l-1]*a[r+1],dp[l][r]);
*/
vector<int>a;
vector<vector<int>>dp;
int var(int l,int r)
{
    //pruning
    if(l>r)return 0;
    //cache check
    if(dp[l][r]!=-1)return dp[l][r];
    //transition
    //for the range l to r I will try on all the possible values of mid
    for(int i=l;i<=r;i++)
    {
        dp[l][r]=max(dp[l][r],var(l,i-1)+var(i+1,r)+a[i]*a[l-1]*a[r+1]);
    }
    //save and return 
    return dp[l][r];
}
int main()
{
    int n;
    cin>>n;
    a.assign(n+2,1);
    dp.assign(n+1,vector<int>(n+1,-1));
    for(int i=1;i<=n;i++)cin>>a[i];
    int ans=var(1,n);
    cout<<ans<<endl;
    return 0;
}