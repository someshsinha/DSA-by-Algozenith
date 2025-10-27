//code for towerofHanoi and the first code for backtarcking
#include<bits/stdc++.h>
using namespace std;
void tower(int discs,int from,int to,int extra)
{
    if(discs==0) return;
    tower(discs-1,from,extra,to);
    cout<<discs<<" from "<<from<<" to "<<to<<endl;
    tower(discs-1,extra,to,from);
}
int main()
{
    tower(3,1,3,2);
    return 0;
}