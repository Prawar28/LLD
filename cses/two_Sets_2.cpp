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
 
ll n;

int main()
{
 
    cin>>n;
    ll totalSum = n * (n + 1) / 2;

    if (totalSum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    totalSum = totalSum / 2;
    vector<ll> dp(totalSum + 1, 0);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        vector<ll> dp2(totalSum + 1, 0);
        dp2[0] = 1;

        for (int j = 1; j <= totalSum; j++) {
            if (j < i) {
                dp2[j] = dp[j];
                continue;
            }

            dp2[j] = (dp[j] + dp[j - i])%M;
            
        }

        dp.swap(dp2);
    }

    cout << (dp[totalSum])<< endl;
    return 0; 
}
