/*
code for bfs here we traverse the 
level by levl instead of going into depth
main code
this is also the solution of the question labyrith from cses problemset

*/
#include<bits/stdc++.h>
using namespace std;
using state=pair<int,int>;
#define F first
#define S second
int INF=100;
vector<string>adj;
vector<vector<int>>dis;
vector<vector<int>>vis;
vector<vector<state>>parent;
vector<vector<char>>move_taken;
int n,m;
bool is_valid(int x,int y)
{
    if(x<0 || x>=n)return 0;
    if(y<0 || y>=m)return 0;
    if(adj[x][y]=='#')return 0;
    return 1;
}
vector<pair<state,char>>neighbour(state i)
{
    vector<pair<state,char>>f;
    int dx[4]={+1,-1,0,0};
    int dy[4]={0,0,+1,-1};
    char move[4]={'D','U','R','L'};
    for(int j=0;j<4;j++)
    {
        if(is_valid(i.F+dx[j],i.S+dy[j]))
        {
            f.push_back({{i.F+dx[j],i.S+dy[j]},move[j]});
        }
    }
    return f;
}
void bfs(state start)
{
    queue<state>q;
    q.push(start);
    vis[start.F][start.S]=1;
    while(!q.empty())
    {
        auto it=q.front();
        q.pop();
        for(auto [e,m]:neighbour(it))
        {
            if(!vis[e.F][e.S])
            {
                parent[e.F][e.S]=it;
                move_taken[e.F][e.S]=m;
                vis[e.F][e.S]=1;
                q.push(e);
                dis[e.F][e.S]=dis[it.F][it.S]+1;
            }
        }
    }
}
int main()
{
    cin>>n>>m;
    adj.resize(n);
    vis.assign(n, vector<int>(m, 0));
    dis.assign(n, vector<int>(m, INF));
    parent.assign(n, vector<state>(m, {-1, -1}));
    move_taken.assign(n,vector<char>(m));
    state start,end;
    for(int i=0;i<n;i++)
    {
        cin>>adj[i];
        for(int j=0;j<m;j++)
        {
            if(adj[i][j]=='A')
            {
                start={i,j};
            }
            else if(adj[i][j]=='B')
            {
                end={i,j};
            }
        }
    }
    dis[start.F][start.S]=0;
    bfs(start);
    if(dis[end.F][end.S]!=INF)
    {
        cout<<"YES"<<endl;
        cout<<dis[end.F][end.S]<<endl;
        //start with B and go uptil node whose parent is A
        string path="";
        state begin=end;
        while(begin!=start)
        {
            path+=move_taken[begin.F][begin.S];
            begin=parent[begin.F][begin.S];
        }
        reverse(path.begin(),path.end());
        cout<<path<<endl;
    }
    else cout<<"NO"<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<m;j++)
    //     {
    //         cout<<dis[i][j]<<"\t";
    //     }
    //     cout<<endl;
    // }
    return 0;
}