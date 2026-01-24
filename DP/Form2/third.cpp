/*
Q) => For the given array, find the k partitions such that , the sum of the minimum of 
each one of the k partitons will be as low as possible ;

1 3 2 5 4 
best 4 + 2 + 1 = 7;

transition dp(i,x)=> dp(j,x-1)+min([i ... j+1]);
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>dp;
vector<int>arr;
int rec(int level,int x)
{
    // pruning
    if(x < 0) return 1e9;

    // base case
    if(level == -1)
    {
        if(x == 0) return 0;
        else return 1e9;
    }

    // cache check (only after ensuring level >= 0)
    if(dp[level][x] != -1) return dp[level][x];

    // transition
    int ans = 1e9;
    int min_element = arr[level];
    for(int i = level-1; i >= -1; i--)
    {
        ans = min(ans, rec(i, x-1) + min_element);
        if(i != -1) min_element = min(min_element, arr[i]);
    }

    return dp[level][x] = ans;
}

signed main()
{
    int n,x;
    cin>>n>>x;
    arr.assign(n,0);
    dp.assign(n,vector<int>(x+1,-1));
    for(int i=0;i<n;i++)cin>>arr[i];
    int answer=rec(n-1,x);
    cout<<answer<<endl;
    return 0;
}
