/*
Basic ways to print the binary representation of a number
*/
//non-iterative approach
#include<bits/stdc++.h>
typedef long long lli;
using namespace std;

int main()
{
    unsigned int x = 7; 
    for(int i=31;i>=0;i--) // looping through each digit from MSB to LSB
    {
        if(x&(1<<i))       // checking current bit is set or not
        {
            cout << '1';
        }
        else cout << '0';
    }
    cout<<endl;
    return 0; 
}

//iterative approach
#include<bits/stdc++.h>
typedef long long lli;
using namespace std;

void printbin(unsigned int x)
{
    if(x>1)
    {
        printbin(x/2);    // recursive call to rest of the bits
    }
    cout<<(x%2);          // print the last bit
}

int main()
{
    unsigned int x = 4; 
    printbin(x);
    return 0; 
}
