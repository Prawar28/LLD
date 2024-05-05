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
    ll n, maxPrice;
    cin >> n >> maxPrice;
    vector<ll> prices(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    vector<ll> pages(n);
    for (int i = 0; i < n; i++) cin >> pages[i];

    vector<ll > dp(maxPrice + 1, 0);

    for (int i = 1; i <= n; i++) {
        int price = prices[i - 1];
        int pageCount = pages[i - 1];
        vector<ll> dp2(maxPrice + 1, 0);
        for (int j = 1; j <= maxPrice; j++) {
            if (price > j) {
                dp2[j] = dp[j];
                // cout << dp[i][j] << " ";
                continue;
            }
            dp2[j] = max(dp[j], dp[j - price] + pageCount);
            // cout << dp[i][j] << " ";
        }
        dp.swap(dp2);
        // cout << endl;
    }

    cout << dp[maxPrice] << endl;
}
 