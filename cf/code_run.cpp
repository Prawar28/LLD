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


ll hcf(int a, int b) {
  return b==0?a:hcf(b, a%b);
}

void primeSeive(ll n,unordered_set<ll>& countPrime) {
  int p = 2;
 
  vector<bool> isPrime(n, true);
 
  while (p*p <= n) {
 
    if (isPrime[p]) {
      for (int i = p*p; i <= n; i += p) {
        isPrime[i] = false;
      }
    }
    p++;
  }

  for (int i = 2; i < n; i++) {
    if (isPrime[i]) {
      countPrime.insert((ll)i*i);
    }
  }
}

int main()
{ 
  ll t;
  cin >> t;

  while (t--) {
    ll n,q;
    cin >> n >> q;

    vector<ll> ps(n + 1, 0);
    vector<ll> marr(n);

    for (int i = 1; i <= n; i++) {
      ll x;
      cin >> x;
      ps[i] = ps[i - 1] + x;

      if (i == 1) marr[i - 1] = x;
      else {
        marr[i - 1] = max<ll>(marr[i - 2], x);
      }
    }
    // cout << endl;
    // for (auto x : ps) cout << x << " ";
    // cout << endl;
    // cout << "max-arr "<< endl;
    // for (auto x : marr) cout << x << " ";
    // cout << endl;
    while (q--) {
      ll x;
      cin >> x;

      int l = 0, r = n - 1;

      while (l <= r) {
        int mid = (l + r)/2;

        if (marr[mid] > x) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }
      // cout << "r: " << r << " ps: ";
      cout << ps[r + 1] << " ";
    }
    cout << endl;
  }
  return 0;
}