#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <stack>
const unsigned int M = 1e9 + 7;
 
#define ll long long
#define pii pair<ll, ll>
using namespace std;
 
int n,x;
int nax = 1e3 + 5;

bool safe(int i, int j) {
    if (i > 0 && i <= n && j > 0 && j <= n) return true;
    return false;
}
int main()
{
 
    cin>>n;
    vector<vector<char> > in(n + 1, vector<char>(n + 1));
 
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin>>in[i][j];
 
    vector<vector<ll> > dp(nax, vector<ll>(nax, 0));
 
    // dp[1][1] = (1 && (in[1][1] != '*'));
    dp[n][n] = 1;
    if(in[n][n] == '*'){
        cout<<0<<endl;
        return 0;
    }
    // for(int i = 2; i <= n; i++) dp[1][i] = (dp[1][i - 1] && (in[1][i]!= '*')),dp[i][1] = (dp[i - 1][1] && (in[i][1]!= '*'));
 
    // for(int i = 2; i <= n; i++){
 
    //     for(int j = 2; j <= n; j++){
 
    //         if(in[i][j] == '*')continue;
 
    //         dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])%M;
 
    //     }
    // }
    for (int i = n; i > 0; i--) {
        for (int j = n; j > 0; j--) {
            if (in[i][j] == '*' || (i == n && j == n)) {
                continue;
            }
            if (safe(i + 1, j) && in[i + 1][j] != '*') dp[i][j] = (dp[i + 1][j] + dp[i][j])%M;
            if (safe(i, j + 1) && in[i][j + 1] != '*') dp[i][j] = (dp[i][j + 1] + dp[i][j])%M;
        }
    }
    // for(int i = 1; i <= n; i++){
    //     for(int j = 1; j <= n; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
        
    cout<<dp[1][1]<<endl;
}
