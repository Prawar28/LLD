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
vector<ll> parent;
vector<vector<ll> > kanc;
vector<ll> dist;

void preprocessTable() {
    ll p = log2(n);
    kanc = vector<vector<ll> >(n + 1, vector<ll>(p + 1));
    
    for (int i = 1; i <= n; i++) {
        kanc[i][0] = parent[i];
        // cout << kanc[i][0] << " ";
    }
    // cout << endl;
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= n; j++) {
            if (kanc[j][i - 1] == -1) kanc[j][i] = -1;
            else kanc[j][i] = kanc[kanc[j][i - 1]][i - 1];

            // cout << kanc[j][i] << " ";
        }
        // cout << endl;
    }

    dist[1] = 0;
    for (int i = 2; i <= n; i++) {
        int node = i;

        ll pow = p;
        int d = 0;
        while (node != 1) {
            // cout << "pow: and kanc[node][pow] " << pow << " " << kanc[node][pow] << endl;
            if (kanc[node][pow] == -1) {
                pow--;
            } else {
                d += (1 << pow);
                node = kanc[node][pow];
                pow = p;
            }
        }
        dist[i] = d;
        // cout << "dist: " << i << " " << d << endl;
    }
}

int kthAnc(int k, int node) {
    ll idx = 0;
    while (k && node!= -1) {
        if (k & 1) {
            node = kanc[node][idx];
        }
        idx++;
        k = k >> 1;
        // cout << 'a' << endl;
    }
    return node;
}

int main()
{
    cin >> n >> q;
    parent = vector<ll>(n + 1, -1);
    dist = vector<ll>(n + 1, -1);

    for (int i = 2; i <= n; i++) {
        ll x;
        cin >> x;
        parent[i] = x;
    }

    preprocessTable();

    // cout << "queries: " << endl;
    while(q--) {
        ll x,y;
        cin >> x >> y;

        if (dist[x] < dist[y]) {
            ll t = x;
            x = y;
            y = t;
        }

        ll k = dist[x] - dist[y];
        // cout << "k: " << k << endl;
        x = kthAnc(k, x);
        if (x == y) {
            cout << x << endl;
            continue;
        }
        
        if (kanc[x][0] == kanc[y][0]) {
            cout << kanc[x][0] << endl;
            continue;
        }

        int depth = dist[x];
        int ans = -1;

        // cout << "depth of nodes" << dist[x] << endl;
        int p = log2(depth);
        // cout << "depth: " << depth << "p " << p << endl;
        // cout << "x and y:" << x << " " << y << endl;
        while ((x != y) && (p >= 0)) {
            int kpx = kanc[x][p];
            int kpy = kanc[y][p];

            // cout << "kpx: " << kpx << "kpy: " << kpy << endl;
            if (kpx == kpy) {
                ans = kpx;
                p--;
            } else {
                x = kpx;
                y = kpy;
            }
            // break;
        }

        cout << ans << endl;
    }
}
