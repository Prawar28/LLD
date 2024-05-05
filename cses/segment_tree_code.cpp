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
vector<ll > seg(4*1000005);

void build(ll index, ll left, ll right) {
    if (left == right) {
        seg[index] = arr[left];
        return;
    }
    ll mid = (left + right) / 2;

    build(2 * index + 1, left, mid);
    build(2 * index + 2, mid + 1, right);

    seg[index] = seg[2 * index + 1] ^ seg[2 * index + 2];
}

void pointUpdate(ll index, ll updateIndex, ll left, ll right, ll updateDiff) {

    if (left == right) {
        seg[index] += updateDiff;
    }

    ll mid = (left + right)/2;
    // if updateIndex > mid it lies between mid + 1 to right
    // else left to mid (updateIndex <= mid)
    if (updateIndex > mid) pointUpdate(2 * index + 2, updateIndex, mid + 1, right, updateDiff);
    else pointUpdate(2 * index + 1, updateIndex, left, mid, updateDiff);
    
    seg[index] = min(seg[2 * index + 1], seg[2 * index + 2]);
}

ll query(ll currNode, ll start, ll end, ll left, ll right) {
    // value does not exist in this range
    if (start > right || end < left) {
        return 0; 
    }

    // if completely lies in the given range
    if (left >= start && right <= end) {
        return seg[currNode];
    }
    ll mid = (right + left)/2;
    ll leftQuery = query(2 * currNode + 1, start, end, left, mid);
    ll rightQuery = query(2 * currNode + 2, start, end, mid + 1, right);
    return leftQuery ^ rightQuery;
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        arr.push_back(x);
    }
    build(0, 0, n - 1);
    // for (int i = 0; i < 2*n - 1; i++) {
    //     cout << seg[i] << " ";
    // }
    while(q--) {
        ll a, b;
        cin>>a>>b;
        --a,--b;
        cout << query(0, a, b, 0, n - 1) << endl;
    }
}
