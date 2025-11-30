//basic dfs aglo 
/*
basic pseudo code:
dfs(x)
{
    vis[x]=1;
    for(auto it:neighbour[x])
    {
        if(!vis[it])dfs(it);
    }
}
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>v;
void dfs(int x)
{
    v[x]=1;
    for(auto it:adj[x])
    {
        if(!v[it])
        {
            dfs(it);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    v.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++)//O(n)
    {
        v.assign(n+1,0);
        dfs(i); //O(n+m)
        for(auto it:v)cout<<it<<" ";//O(n); 
        cout<<endl;
    }
    return 0;
}

/*
Time complexity:
O(n*(n+m));
*/