#include<bits/stdc++.h>
using namespace std;
vector<int>answer;
vector<int>input;
int n;
void printer()
{
    for(auto it:answer){
        cout<<it<<" ";
    }
    cout<<endl;
}
void subset(int r){
    if(r==n)
    {
        printer();
        return;
    }
    
        //to take
        answer.push_back(input[r]);
        subset(r+1);
        answer.pop_back();
        //to not take
        subset(r+1);
}
int main()
{
    cout<<"Please enter the size of the array: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        input.push_back(k);
    }
    subset(0);
    return 0;
}