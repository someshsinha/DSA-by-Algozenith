/*
Question => given the two string s and t
find the longest common substring in both of them
*/
#include<bits/stdc++.h>
using namespace std;
string s,t;
vector<vector<int>>dp;
int n,m;
//here i is the index for string s 
//here j is the index for string t;
int rec(int i,int j)
{
    //pruning
    if(i<0 || j<0)return 0;
    //base condition
    if(i==n || j==m)
    {
        return 0;
    }
    //cache check
    if(dp[i][j]!=-1)return dp[i][j];
    //transition
    int ans=0;
    if(s[i]==t[j])
    {
        ans=1+rec(i+1,j+1);
    }
    //save and return 
    dp[i][j]=ans;
    return ans;
}
int main()
{
   cin>>s>>t;
    n=(int)s.size();
    m=(int)t.size();
    dp.assign(n,vector<int>(m,-1));
    vector<int>init;
    int maxi=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maxi<rec(i,j))
            {
                vector<int>b={i};
                init=b;
                maxi=rec(i,j);
            }
            else if(maxi==rec(i,j))
            {
                init.push_back(i);
            }
        }
    }
    for(auto it:init)
    {
        cout<<s.substr(it,maxi)<<endl;
    }
    cout<<maxi<<endl;
    return 0;
}