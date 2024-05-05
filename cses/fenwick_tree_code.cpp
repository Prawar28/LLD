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
vector<ll > bitTree;

void updateQuery(ll i, ll value) {
    while (i < bitTree.size()) {
        bitTree[i] += value;
        i = i + (i&(-i));
    }
}

ll sumQuery(ll i) {
    ll sum = 0;
    while(i > 0) {
        sum += bitTree[i];
        i = i - (i&(-i));
    }

    return sum;
}

void updateAtIndex(ll i, ll val) {
    ll value = val - arr[i];
    arr[i] = val;
    updateQuery(i, value);
}

int main()
{
    cin >> n >> q;
    arr.push_back(0);
    for (int i = 1; i <= n; i++) {
        ll x;
        cin >> x;
        arr.push_back(x);
    }

    bitTree = vector<ll> (n + 1, 0);
    for (int i = 1; i <= n; i++) {
        updateQuery(i, arr[i]);
    }

    while(q--) {
        ll qt, a, b;
        cin>>qt>>a>>b;

        if (qt == 1) {
            updateAtIndex(a, b);
        } else {
            cout << sumQuery(b) - sumQuery(a - 1) << endl;
        }
    }
}
