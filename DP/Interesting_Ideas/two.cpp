/*
Problem: Longest Bitonic Subsequence

Statement:Given an array of integers nums, find the length of the longest Bitonic Subsequence.

A subsequence of an array is called Bitonic if it is first strictly increasing and then strictly decreasing.

The increasing part or the decreasing part can be empty (e.g., a purely increasing sequence is considered bitonic in some definitions, but strictly speaking, a bitonic sequence usually implies a "peak").Formally, a subsequence x_1, x_2, ..., x_k is bitonic if there exists an index j (1 <= j <= k) such that:x_1 < x_2 < ... < x_j > x_{j+1} > ... > x_k

Input:The first line contains an integer N (the size of the array).

The second line contains N space-separated integers representing the array nums.

Output:Output a single integer representing the length of the longest bitonic subsequence.
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //longest bitonic sequcned if ending at i => 
    //lis[i]+lds[i]-1
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>inserted;
    vector<int>len;
    for(int i=0;i<n;i++)
    {
        auto it=lower_bound(len.begin(),len.end(),a[i]);
        if(it==len.end())
        {
            len.push_back(a[i]);
            inserted[i]=(int)len.size()-1;
        }
        else
        {
            int index=it-len.begin();
            len[index]=a[i];
            inserted[i]=index;
        }
    }
    vector<int>dec;
    vector<int>inserted2;
    //now get the longest decreasign subseqence starting at index i
    for(int i=n-1;i>=0;i--)
    {
        auto it=upper_bound(dec.begin(),dec.end(),a[i])-dec.begin()+1;
        if(it>=(int)dec.size())
        {
            dec.push_back(a[i]);
            inserted2[i]=(int)dec.size()-1;
        }
        else
        {
            dec[it]=a[i];
            inserted2[i]=it;
        }
    }
    //finally we got the longest increaseing subsequence as well as longest decreasing subsequence
    int maxi=0;
    int idx=0;
    for(int i=0;i<n;i++)
    {
        int times=inserted[i]+inserted2[i]+1;
        if(times>=maxi)
        {
            idx=i;
            maxi=times;
        }
    }
    cout<<maxi<<endl;
    //after this we want to get the longest increasing subsequence ending at i beginning from 0 
    // and also longest decreasing subsequence beginning at i and going to n-1
    int start=a[idx];
    //increasing subsequcned
    vector<int>final(inserted[idx]+inserted2[idx]+1,-1);
    final[idx]=a[idx];
    int find=idx-1;
    for(int i=idx-1;i>=0;i--)
    {
        if(inserted[i]==find)
        {
            final[find]=a[i];
            find--;
        }
    }
    for(int i=n-1;i>idx;i--)
    {
        if(final[inserted[i]]==-1)
        {
            final[inserted[i]]=a[i];
        }
    }
    for(auto it:final)cout<<it<<" ";
    cout<<endl;
    return 0;
}