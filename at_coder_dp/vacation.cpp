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
 
    cin>>n;
    vector<ll> swim(n);
    vector<ll> bugs(n);
    vector<ll> home(n);
    for (int i = 0; i < n; i++) {
        cin >> swim[i];
        cin >> bugs[i];
        cin >> home[i];
    }

    ll s0 = swim[0];
    ll b0 = bugs[0];
    ll h0 = home[0];

    for (int i = 1; i < n; i++) {
        ll sx = max<ll>(b0, h0) + swim[i];
        ll bx = max<ll>(h0, s0) + bugs[i];
        ll hx = max<ll>(s0, b0) + home[i];

        s0 = sx;
        b0 = bx;
        h0 = hx;
        // cout << s0 << " " << b0 << " " << h0 << endl;
    }
    cout << max<ll>(s0, max<ll>(b0, h0)) << endl;
    return 0; 
}
