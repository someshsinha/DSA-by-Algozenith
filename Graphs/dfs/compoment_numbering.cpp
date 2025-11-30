/*
in this way we associate a number with every part that we can reach starting from a single node
and then then helps reduce the number of loop which we have to do
*/
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>adj;
vector<int>v;
vector<int>component_number;
void dfs(int x,int cnt)
{
    v[x]=1;
    component_number[x]=cnt;
    for(auto it:adj[x])
    {
        if(!v[it])
        {
            dfs(it,cnt);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    adj.resize(n+1);
    v.resize(n+1);
    component_number.resize(n+1);
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt=1;
    for(int i=1;i<=n;i++) //O(n);
    {
        if(!v[i])
        {
            dfs(i,cnt); //O(n+m);
            cnt++;
        }
    }
    vector<int>count_component(cnt);
    for(int i=1;i<=n;i++)
    {
        count_component[component_number[i]]++;
    }
    for(auto it:count_component)cout<<it<<" ";
    cout<<endl;
    return 0;
}

/*
CALCULATE IT'S TIME COMPLEXITY:
here we visit each node exactly once: it's just that earlier we had to traverse the entire thing every time
now that was no longer required since we got a mechanism to store the family into a vector

O(n+m);
*/