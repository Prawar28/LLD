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

int main()
{
    string s,t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();

    vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            // cout << dp[i][j] << " ";
        }
        // cout << endl;
    }

    string ans = "";
    int len = dp[n][m];
    int i = n;
    int j = m;
    while (len > 0) {
        if (s[i - 1] == t[j - 1] && dp[i - 1][j - 1] + 1 == dp[i][j]) {
            ans = s[i - 1] + ans;
            i--;
            j--;
            len--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    cout << ans << endl;
}
 