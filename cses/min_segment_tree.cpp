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

    ll mid = (right + left)/2;
    build(2 * index + 1, left, mid);
    build(2* index + 2, mid + 1, right);

    seg[index] = min(seg[2 * index + 1], seg[2* index + 2]);
}

void pointUpdate(ll index, ll updateIndex, ll left, ll right, ll updateDiff) {
    if (left == right) {
        seg[index] = updateDiff;
        return;
    }
    ll mid = (right + left)/2;
    if (updateIndex <= mid) pointUpdate(2 * index + 1, updateIndex, left, mid, updateDiff);
    else pointUpdate(2 * index + 2, updateIndex, mid + 1, right, updateDiff);

    seg[index] = min(seg[2 * index + 1], seg[2* index + 2]);        
}

ll query(ll index, ll start, ll end, ll left, ll right) {
    if (end < left || start > right) {
        return LLONG_MAX;
    }

    if (left >= start && right <= end) {
        return seg[index];
    }

    ll mid = (right + left) / 2;
    ll x = query(2 * index + 1, start, end, left, mid);
    ll y = query(2 * index + 2, start, end, mid + 1, right);

    return min(x, y);
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

    while(q--) {
        ll qt, a, b;
        cin>>qt>>a>>b;
        if (qt == 1) {
            --a;
            pointUpdate(0, a, 0, n - 1, b);
            arr[a] = b;
        } else {
            --a,--b;
            cout << query(0, a, b, 0, n - 1) << endl;
        }
    }
}
