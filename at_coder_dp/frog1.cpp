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
 
ll n,t;

int main()
{
 
    cin>>n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    ll x_1 = abs(arr[0] - arr[1]);
    ll x_2 = 0;

    for (int i = 2; i < n; i++) {
        ll x = abs(arr[i] - arr[i - 1]) + x_1;
        ll y = abs(arr[i] - arr[i - 2]) + x_2;
        ll cost_x = min<ll>(x, y);
        // cout << cost_x << " ";
        x_2 = x_1;
        x_1 = cost_x;
    }
    // cout << endl;
    cout << x_1 << endl;
    return 0; 
}
