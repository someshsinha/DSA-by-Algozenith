/*
Here we have to find the diameter of the thing
so to find the diameter what we do is 
take any node and then find the largets distance from from that node 
then take that node and then find the largest distrance from that node
so this distance will be the diameter
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>g[100100];
int depth[100100];
void dfs(int s,int p,int d)
{
    depth[s]=d;
    for(auto v:g[s])
    {
        if(v!=p)
        {
            dfs(v,s,d+1);
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0,0);
    //find the node with the largest distance 
    int matchx=1;
    for(int i=1;i<=n;i++)
    {
        if(depth[i]>depth[matchx])
        {
            matchx=i;
        }
    }
    dfs(matchx,0,0);
    int matchx2=1;
    for(int i=1;i<=n;i++)
    {
        if(depth[i]>depth[matchx2])
        {
            matchx2=i;
        }
    }
    cout<<depth[matchx2]-depth[matchx]<<endl;
    return 0;
}