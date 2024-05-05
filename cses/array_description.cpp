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
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<ll > dp;

    if (arr[0] == 0) {
        dp = vector<ll>(m + 2, 1);
        dp[0] = 0;
        dp[m + 1] = 0;
    } else{
        dp = vector<ll>(m + 2, 0);
        dp[arr[0]] = 1;
    }
    // since you could notice at every iteration you only require result from the i - 1, we could ignore others
    for (int i = 2; i <= n; i++) {
        vector<ll> dp2(m + 2, 0);
        if (arr[i - 1] == 0) {
            for (int j = 1; j <= m; j++) {
                dp2[j] = (dp2[j] + dp[j])%M;
                dp2[j] = (dp2[j] + dp[j - 1])%M;
                dp2[j] = (dp2[j] + dp[j + 1])%M;
                // cout << dp2[j] << " ";
            }
        } else {
            dp2[arr[i - 1]] = (dp2[arr[i - 1]] + dp[arr[i - 1]])%M;
            dp2[arr[i - 1]] = (dp2[arr[i - 1]] + dp[arr[i - 1] - 1])%M;
            dp2[arr[i - 1]] = (dp2[arr[i - 1]] + dp[arr[i - 1] + 1])%M;
            // cout << dp2[arr[i - 1]];
        }
        dp2[0] = 0;
        dp2[m + 1] = 0;
        // cout << endl;
        dp.swap(dp2);
        // cout << endl;
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + dp[i])%M;
    }

    cout << ans << endl;
}
 