#include<bits/stdc++.h>
using namespace std;

// Size 5 to handle states -1 to 3 (mapped to indices 0 to 4)
long long dp[1001][5][5]; 
string s;
int n;

long long rec(int i, int prev, int nfs)
{
    // base condition
    if(i == n){
        // Cyclic check: Last char (prev) must not equal First char (nfs)
        if(prev != nfs) return 1;
        else return 0;
    }
    
    // cache check (Indices shifted by +1 to handle -1)
    if(dp[i][prev + 1][nfs + 1] != -1)
    {
        return dp[i][prev + 1][nfs + 1];
    }
    
    // transition
    long long ans = 0;
    if(s[i] == '?')
    {
        for(int j = 0; j < 4; j++)
        {
            if(j != prev)
            {
                int fs = nfs;
                if(nfs == -1) fs = j; // Set first state if unset
                ans += rec(i + 1, j, fs);
            }
        }
    }
    else
    {
        int curr = s[i] - 'A';
        if(curr != prev)
        {
            int fs = nfs;
            if(nfs == -1) fs = curr; // Set first state if unset
            ans = rec(i + 1, curr, fs);
        } 
        else ans = 0;
    }
    
    // save and return (Indices shifted by +1)
    return dp[i][prev + 1][nfs + 1] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    memset(dp, -1, sizeof(dp));
    
    cout << rec(0, -1, -1) << endl;
    return 0;
}
/*
dp state will be
dp[i][previous][first_state]=>{number of ways in which you can generate a valid cyclic string};
t.c => 16n
*/