//code for nCr
#include<bits/stdc++.h>
using namespace std;
int nCr(int n,int r){
    if(n<r)return 0;
    if(n==0 || r==0)return 1;
    return nCr(n-1,r-1)+nCr(n-1,r);
}
int main()
{
    int answer=nCr(1,1);
    cout<<answer<<endl;
    return 0;
}