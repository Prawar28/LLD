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
}

int main()
{
    cin >> n >> q;
    parent = vector<ll>(n + 1, -1);

    for (int i = 2; i <= n; i++) {
        ll x;
        cin >> x;
        parent[i] = x;
    }

    preprocessTable();

    // cout << "queries: " << endl;
    while(q--) {
        ll x,k;
        cin >> x >> k;

        ll idx = 0;
        ll node = x;
        while (k && node!= -1) {
            if (k & 1) {
                node = kanc[node][idx];
            }
            idx++;
            k = k >> 1;
            // cout << 'a' << endl;
        }
        cout << node << endl;
    }
}
