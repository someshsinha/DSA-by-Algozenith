#include<bits/stdc++.h>
using namespace std;
//solution for NQueens problem
vector<int>queens;
int n;
void printer()
{
    for(auto it:queens)cout<<it<<" ";
    cout<<endl;
}
bool allowed(int i,int r)
{
    for(int j=0;j<r;j++)
    {
        //slope y=queens[j] and x is j
        if(queens[j]==i){
            return 0;
        }
    }
    return 1;
}
void permutations(int r)
{
    if(r==n){
        printer();
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(allowed(i,r)){
            queens.push_back(i);
            permutations(r+1);
            queens.pop_back();
        }
    }
}
int main()
{
    cin>>n;
    permutations(0);
    return 0;
}