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
 
ll n,k;

int main()
{
 
    cin>>n>> k;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<ll> dp(n);
    dp[0] = 0;
    dp[1] = abs(arr[0] - arr[1]);
    for (int i = 2; i < n; i++) {
        ll x = LLONG_MAX;
        for (int j = i - 1; j >= max<ll>(0, (i - k)); j--) x = min(x, abs(arr[i] - arr[j]) + dp[j]);

        dp[i] = x;
    }
    // cout << endl;
    cout << dp[n - 1] << endl;
    return 0; 
}
