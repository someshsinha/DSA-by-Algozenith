/*
Find the longest common subsequence in the give two string s and t
*/
#include<bits/stdc++.h>
using namespace std;
string s,t;
vector<vector<int>>dp;
int n,m;
int rec(int i,int j)
{
    //pruning
    if(i<0 || j<0)return 0;
    //base condition
    if(i==n || j==m)return 0;
    //cache check
    if(dp[i][j]!=-1)return dp[i][j];
    //transition
    int ans=max(rec(i+1,j),rec(i,j+1));
    if(s[i]==t[j])
    {
        ans=max(ans,1+rec(i+1,j+1));
    }
    //save and return 
    return dp[i][j]=ans;
}
string g="";
void generate(int i,int j)
{
    if(i<0 || j<0)return ;
    if(i==n || j==m)return ;
    if(s[i]==t[j])
    {
        //include it
        g+=s[i];
        generate(i+1,j+1);
    }
    else{
        int valueSkipJ=rec(i,j+1);
        int valueSkipI=rec(i+1,j);
        if(valueSkipJ>valueSkipI)
        {
            generate(i,j+1);
        }
        else generate(i+1,j);
    }
}
int main()
{
    cin>>s>>t;
    n=(int)s.size();
    m=(int)t.size(); 
    dp.assign(n,vector<int>(m,-1));
    int maxi=rec(0,0);
    generate(0,0);
    cout<<g<<endl;
    cout<<maxi<<endl;
    return 0;
}