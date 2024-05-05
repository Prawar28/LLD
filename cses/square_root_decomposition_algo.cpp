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
vector<ll> block;
int blockSize;

int rangeQuery(ll x, ll y) {
    --x,--y;
    ll minVal = LLONG_MAX;

    while (x < y && x%blockSize != 0 && x != 0) {
        minVal = min(minVal, arr[x]);
        x++;
    }

    while (x + blockSize - 1 <= y) {
        minVal = min(minVal, block[x / blockSize]);
        x += blockSize;
    }

    while (x <= y) {
        minVal = min(minVal, arr[x]);
        x++;
    }

    return minVal;
}

int main()
{
    cout << "hello" << endl;
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        arr.push_back(x);
    }

    blockSize = sqrt(n);
    block = vector<ll> (n + 1, LLONG_MAX);

    ll blockNo = -1;

    for (int i = 0; i < n; i++) {
        if (i % blockSize == 0) {
            blockNo++;
        }
        block[blockNo] = min(block[blockNo], arr[i]);
    }

    for (int i = 0; i < q; i++) {
        ll x,y;
        cin >> x >> y;
        cout << rangeQuery(x, y) << endl;
    }
}
