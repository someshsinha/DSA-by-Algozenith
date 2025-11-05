#include<bits/stdc++.h>
using namespace std;
//so basically if I normally do things then it will be incorrect because 
//two same element will have distince indices so the recursion may treat them different
//but if we somehow assimilate their similar indices and use a characteristic whihc will make the two similar elemtns similar then probably we can succeed
map<int,int>m;
vector<int>answer;
int n;
void printer(){
    for(auto it:answer)cout<<it<<" ";
    cout<<endl;
}
void permute(int r){
    if(r==n){
        printer();
        return;
    }
    //for each element if it exists then either include it or ignore it
    for(auto it:m){
        if(it.second>=1){
            //include
            answer.push_back(it.first);
            m[it.first]--;
            permute(r+1);
            m[it.first]++;
            answer.pop_back();
            //not-include
            m[it.first]--;
            permute(r+1);
            m[it.first]++;
        }
    }
}
int main(){
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
        m[k]++;
    }
    permute(0);
    return 0;
}