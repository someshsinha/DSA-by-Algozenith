<<<<<<< HEAD
//You can identify a tree by any of the three definations
/*
1)There are N nodes which are connected to each other using N-1 edges
2)Each node is connected to each other using a simple edge
3)between each pair of nodes there is only 1 connected component and no cycles
*/
/*
This code is for basic tree traversal and to find
1)depth of each node
2)parent of each node
3)isLeaf or not for each node
4)count of subtrees for each node
5)number of child for each node
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>g[100100];
vector<int>depth[100100];
vector<bool>isLeaf[100100];
vector<int>parent[100100];
vector<int>subtree[100100];
vector<int>numChild[100100];
void bfs(int root,int p,int d)
{
    depth[root]=d;
    parent[root]=p;
    for(auto v:g[root])
    {
        if(v!=p)
        {
            numChild[root]++;
            dfs(v,root,d+1);
            subtree[root]+=subtree[v];
        }
    }
    if(numChild[root]==0)isLeaf[root]=true;
    else isLeaf[root]=false;
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
    int root;
    cin>>root;
    dfs(root,0,0);
    /* Printing the information */
    cout << "\nNode\tDepth\tParent\tIsLeaf\tSubtree\tChildren\n";
    cout << "------------------------------------------------------\n";
    for(int i = 1; i <= n; i++) {
        cout << i << "\t" 
             << depth[i] << "\t" 
             << parent[i] << "\t" 
             << (isLeaf[i] ? "Yes" : "No") << "\t" 
             << subtree[i] << "\t" 
             << numChild[i] << "\n";
    }
    return 0;
}
=======
//You can identify a tree by any of the three definations
/*
1)There are N nodes which are connected to each other using N-1 edges
2)Each node is connected to each other using a simple edge
3)between each pair of nodes there is only 1 connected component and no cycles
*/
/*
This code is for basic tree traversal and to find
1)depth of each node
2)parent of each node
3)isLeaf or not for each node
4)count of subtrees for each node
5)number of child for each node
*/
#include<bits/stdc++.h>
using namespace std;

// ONLY the graph should be a vector array
vector<int> g[100100];

// These should be simple arrays because each node has only ONE of these values
int depth[100100];
bool isLeaf[100100];
int parent[100100];
int subtree[100100];
int numChild[100100];

void dfs(int root, int p, int d) {
    depth[root] = d;
    parent[root] = p;
    subtree[root] = 1; // Start with 1 (the node itself)
    numChild[root] = 0; // Initialize children count to 0

    for(auto v : g[root]) {
        if(v != p) {
            numChild[root]++;
            dfs(v, root, d + 1);
            subtree[root] += subtree[v]; // This now works because it's int + int
        }
    }
    
    // Check if it's a leaf
    if(numChild[root] == 0) isLeaf[root] = true;
    else isLeaf[root] = false;
}

int main() {
    int n;
    if(!(cin >> n)) return 0;

    for(int i = 1; i <= n - 1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int root;
    cin >> root;
    dfs(root, 0, 0);

    /* Printing the information */
    cout << "\nNode\tDepth\tParent\tIsLeaf\tSubtree\tChildren\n";
    cout << "------------------------------------------------------\n";
    for(int i = 1; i <= n; i++) {
        cout << i << "\t" 
             << depth[i] << "\t" 
             << parent[i] << "\t" 
             << (isLeaf[i] ? "Yes" : "No") << "\t" 
             << subtree[i] << "\t" 
             << numChild[i] << "\n";
    }

    return 0;
}
>>>>>>> 1fd323e83ec4a4336bda6377f735bd203a88fedc