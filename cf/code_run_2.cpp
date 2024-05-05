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

int main()
{
  int t;
  cin >> t;

  while (t--) {

    ll n,k;
    cin >> n >> k;

    if (k < n) cout << k << endl;
    else if (k%(n - 1)) {
      ll x =  k/(n - 1);
      ll y = k % (n - 1);

      cout << (n*x) + y << endl;
    } else {
      ll x =  k/(n - 1);
      cout << (n*x) - 1 << endl;
    }
  }
  return 0;
}
