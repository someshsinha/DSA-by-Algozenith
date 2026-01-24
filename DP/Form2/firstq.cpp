/*
question lis
For the given array find the longest increasing subsequence
*/
#include<bits/stdc++.h>
using namespace std;
int dp[1001];
vector<int>a;
int rec(int level)
{
    //pruning
    if(level<0)return 0;
    //base condition
    //cache check
    if(dp[level]!=-1)return dp[level];
    //transition
    //I am ending my array at index i
    //All the elements that can be included before it will have to have a value much lesser than i
    int ans=1;
    for(int i=0;i<level;i++)
    {
        if(a[level]>a[i])
        ans=max(ans,1+rec(i));
    }
    //save and return and answer
    dp[level]=ans;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    a.assign(n,0);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>a[i];
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,rec(i));
    }
    cout<<maxi<<endl;
    return 0;
}