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
vector<ll > lazy(4*1000005, 0);

void build(ll index, ll left, ll right) {
    if (left == right) {
        seg[index] = arr[left];
        return;
    }
    ll mid = (left + right) / 2;

    build(2 * index + 1, left, mid);
    build(2 * index + 2, mid + 1, right);

    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
}

// range updates like update value of l to r by k | remember the difference betweeen to and by
void lazyRangeUpdate(ll index, ll left, ll right, ll start, ll end, ll updateValue) {
    // lazy update if any pending
    if (lazy[index] != 0) {
        seg[index] += (right - left + 1) * lazy[index] ;
        // propagate the change to further low range nodes if anys
        if (right != left) {
            lazy[2 * index + 1] += lazy[index] ;
            lazy[2 * index + 2] += lazy[index] ;
        }
        lazy[index] = 0;
    }

    // return if out of current range
    if (end < left || start > right) {
        return;
    }

    // if the current range lies completely inside the range we queried to udpate
    if (left >= start && right <= end) {
        seg[index] += (right - left + 1) * updateValue;
        if (left != right) {
            lazy[2 * index + 1] += updateValue;
            lazy[2 * index + 2] += updateValue;
        }
        return;
    }

    ll mid = (right + left)/2;
    lazyRangeUpdate(2 * index + 1, left, mid, start, end, updateValue);
    lazyRangeUpdate(2 * index + 2, mid + 1, right, start, end, updateValue);
    seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
}

ll querySumLazy(ll index, ll start, ll end, ll left, ll right) {
    // lazy update if any pending
    if (lazy[index] != 0) {
        seg[index] += (right - left + 1) * lazy[index] ;
        // propagate the change to further low range nodes if anys
        if (right != left) {
            lazy[2 * index + 1] += lazy[index];
            lazy[2 * index + 2] += lazy[index];
        }
        lazy[index] = 0;
    }

    if (end < left || start > right) {
        return 0;
    }

    // if completely lies in the given range
    if (start >= left && end <= right) {
        return seg[index];
    }
    ll mid = (right + left)/2;
    ll leftQuery = querySumLazy(2 * index + 1, start, end, left, mid);
    ll rightQuery = querySumLazy(2 * index + 2, start, end, mid + 1, right);
    return leftQuery + rightQuery;
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
    // for (int i = 0; i < 2*n - 1; i++) cout << seg[i] << " ";
    while(q--) {
    }
}
