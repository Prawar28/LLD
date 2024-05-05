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
#include <iomanip>

const unsigned int M = 1e9 + 7;
 
#define ll long long
#define dd long double
#define pii pair<ll, ll>
using namespace std;

int main()
{

    ll n;
    cin>>n;
    vector<int> sushi(n);
    for (int i = 0; i < n; i++) cin >> sushi[i];

    vector<dd> dp(n + 1, 0);
    dp[0] = 1;
    
    dd ans = 0;
    // since at most 3 dishes could be there, we could count number of dishes with (1, 2 and 3 sushi respectively)
    // also, if we pick a dish with 2 or 3 sushi, it respectively falls into (1 and 2 pile after we pick)
    // so, basic concept is to solve for (A,B,C) WITH A BEING NUMBER OF PILE WITH 1 SUSHI B = 2 AND C= 3S
    // f(i, j, k) = f(i - 1, j, k) * i + f(i + 1, j - 1, k) * j + f(i, j + 1, k - 1) * k / (i + j + k)
    for (int i = n/2 + 1; i <= n; i++) ans += dp[i];
    cout << fixed << setprecision(9) << ans << endl;
}
 