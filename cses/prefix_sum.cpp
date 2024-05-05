#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <queue>
const unsigned int M = 1e9 + 7;
 
#define ll long long
#define pii pair<ll, ll>
using namespace std;
 
int n, q;
vector<ll> arr;
 
int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        arr.push_back(x);
    }

    vector<ll> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i -1] + arr[i - 1];
    }

    for (int i = 0; i < q; i++) {
        int l,r;
        cin >> l >> r;
        // ans.push_back(prefixSum[l] - prefixSum[r - 1]);
        cout << prefixSum[r] - prefixSum[l - 1] << endl;;
    }
}
