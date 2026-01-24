/*
Statement:Given an integer array nums, return the length of the longest strictly increasing subsequence.
(A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements.

For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Input:The first line contains an integer N (the size of the array).
The second line contains N space-separated integers representing the array nums.
Output:Output a single integer representing the length of the longest increasing subsequence.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    //earlier on we used dp to solve the lis problem but in here we will use
    //but in here we will use greedy + binary search to solve this problem
    //obs : for the same length it is better to have smaller element at the end
    //so for each length look for the first value greater than it and replace it in there
    //in this way you will get the the longest subsequence length
    //inorder to backtrack you need to create another array to ensure that no other element is overriten after the longest length subsequeuce has been formed
    vector<int>len;
    vector<int>inserted(n);
    for(int i=0;i<n;i++)
    {
        auto it=lower_bound(len.begin(),len.end(),a[i]);
        if(it==len.end()){
            len.push_back(a[i]);
            inserted[i]=(int)len.size()-1;
        } 
        else{
            *it=a[i];
            int index=it-len.begin();
            inserted[i]=index;
        } 
    }
    //maximum length
    int currmax=(int)len.size();
    cout<<currmax<<endl;
    int find=currmax-1;
    vector<int>final(currmax);
    for(int i=n-1;i>=0;i--)
    {
        if(inserted[i]==find)
        {
            final[find]=a[i];
            find--;
        }
    }
    for(int i=0;i<n;i++)cout<<inserted[i]<<" ";
    cout<<endl;
    for(auto it:final)cout<<it<<" ";
    cout<<endl;
    //for(int i=0;i<currmax;i++)
    //cout<<len[i]<<" ";
    //cout<<endl;
    return 0;
}
