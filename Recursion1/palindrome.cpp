//recursive code for palindrom check
#include<bits/stdc++.h>
using namespace std;
int palindrome(int l,int r,string s)
{
    //when l==r then I can return
    if(l>=r)return 1;
    if(s[l]!=s[r])return 0;
    return palindrome(l+1,r-1,s);
}
int main()
{
    string s="abccbe";
    int answer=palindrome(0,(int)s.size()-1,s);
    cout<<answer<<endl;
    return 0;
}