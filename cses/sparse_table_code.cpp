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
vector<vector<ll> > minSparseMat;

void preprocessTable() {
    ll p = log2(n);
    minSparseMat = vector<vector<ll> >(p + 1, vector<ll>(n));
    
    for (int i = 0; i < n; i++) minSparseMat[0][i] = arr[i];

    for (int i = 1; i <= p; i++) {
        for (int j = 0; (j + (1 << i) - 1) < n; j++) {
            ll x = minSparseMat[i - 1][j];
            ll y = minSparseMat[i - 1][j + (1 << (i - 1))];
            minSparseMat[i][j] = min(x, y);
        }
    }
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        arr.push_back(x);
    }

    preprocessTable();

    while(q--) {
        ll l,r;
        cin>>l>>r;
        --l,--r;
        ll dif = r - l + 1;
        ll p = log2(dif);

        cout << min(minSparseMat[p][l], minSparseMat[p][r - (1 << p) + 1]) << endl;
    }
}
