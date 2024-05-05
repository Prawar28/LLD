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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    ll totalSum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        totalSum += arr[i];
    }

    vector<bool> dp(totalSum + 1);
    dp[0] = true;
    ll maxSum = 0;
    for (ll i = 1; i <= n; i++) {
        vector<bool> dp2(totalSum + 1, 0);
        dp2[0] = true;
        for (ll j = 1; j <= totalSum; j++) {
            if (arr[i] > j) {
                dp2[j] = dp[j];
                continue;
            }
            dp2[j] = dp[j] || dp[j - arr[i - 1]];
            if (i == n && j <= (totalSum / 2)) {
                if (dp2[j]) maxSum = max(maxSum, j);
            }
        }
        dp.swap(dp2);
    }
    cout << totalSum - 2*maxSum << endl;
}
 