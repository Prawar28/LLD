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
    ll n, maxWeight;
    cin >> n >> maxWeight;
    vector<ll> weight(n);
    vector<ll> value(n);
    ll maxValue = 0;
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
        cin >> value[i];
        maxValue += value[i];
    }

    vector<ll > dp(maxValue + 1, LLONG_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        ll wgh = weight[i - 1];
        ll val = value[i - 1];
        vector<ll> dp2(maxValue + 1, LLONG_MAX);
        dp2[0] = 0;
        for (int j = 1; j <= maxValue; j++) {
            if (val > j) {
                dp2[j] = dp[j];
                // cout << dp[i][j] << " ";
                continue;
            }
            if (dp[j - val] != LLONG_MAX) dp2[j] = min<ll>(dp[j], dp[j - val] + wgh);
            else dp2[j] = dp[j];
            // cout << dp2[j] << " ";
        }
        dp.swap(dp2);
        // cout << endl;
    }

    ll ans = 0;
    for (int i = 1; i <= maxValue; i++) {
        if (dp[i] <= maxWeight) ans = i;
    }

    cout << ans << endl;
}
 