#include<bits/stdc++.h>
using namespace std;

// Using long long to prevent overflow
vector<vector<long long>> dp;
string s;
int n;

long long rec(int i, int prev)
{
    // base condition
    if(i == n){
        return 1;
    }
    // cache check
    if(dp[i][prev] != -1)
    {
        return dp[i][prev];
    }
    // transition
    long long ans = 0;
    if(s[i] == '?')
    {
        for(int j = 0; j < 4; j++)
        {
            if(j != prev)
            {
                ans += rec(i + 1, j);
            }
        }
    }
    else
    {
        // Fix: logic to handle fixed characters
        if((s[i] - 'A') != prev)
        {
            ans = rec(i + 1, s[i] - 'A');
        }
        else 
        {
            ans = 0;
        }
    }
    // save and return 
    return dp[i][prev] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    // Size 5 to handle the '4' dummy state safely
    dp.assign(n + 1, vector<long long>(5, -1));
    
    // Start with 4 (no previous neighbor)
    cout << rec(0, 4) << endl;
    return 0;
}
/*
dp state will be
dp[i][previous]=>{number of ways in which you can generate a valid string from this };
t.c => 4n
*/