/*
bipartite graph --> can be graph be parted in two groups such that vertex in one group is only connected to vertex to another group only and not to his own group
or in other words
can we color the graph with two colors such that two vertices of same color do not intersect
*/
#include<bits/stdc++.h>
using namespace std;
bool is_partitite=0;
vector<vector<int>>adj;
vector<int>v;
vector<int>cc;
void dfs(int x,int c)
{
    v[x]=1;
    cc[x]=c;
    for(auto it:adj[x])
    {
        if(!v[it])dfs(it,3-c);
        else 
        {
            if(cc[it]==c)is_partitite=1;
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    v.resize(n+1);
    cc.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //now what bipartite the thing
    int c=1;
    for(int i=1;i<=n;i++)
    {
        if(!v[i])dfs(i,c);
    }
    //cout the bipartitite
    if(is_partitite==1)cout<<"The graph is not bipartitite"<<endl;
    else
    {
        for(int i=1;i<=n;i++){
            if(cc[i]==1)cout<<i<<" ";
        }
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            if(cc[i]==2)cout<<i<<" ";
        }
        cout<<endl;
    }
    // for(auto it:cc)cout<<it<<" ";
    // cout<<endl;
    return 0;
}