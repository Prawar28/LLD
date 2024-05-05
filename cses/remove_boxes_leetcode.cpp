#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
#include <stack>
const unsigned int M = 1e9 + 7;
 
#define ll long long
#define pii pair<ll, ll>
using namespace std;

int dp[102][102][102];
int solve(int i, int j, int k, vector<int>& boxes) {
    if (i > j) return 0;
    if (dp[i][j][k] > 0) return dp[i][j][k];

    int x = i, y = k;
    while (boxes[x] == boxes[x + 1] && x + 1 <= j) x++,y++;
    int ans = (y + 1) * (y + 1) + solve(x + 1, j, 0, boxes);

    for (int m = x + 1; m <= j; m++) {
        if (boxes[x] == boxes[m]) ans = max(ans, solve(x + 1, m - 1, 0, boxes) + solve(m, j, y + 1, boxes));
    }

    dp[i][j][k] = ans;
    return ans;
}

int removeBoxes(vector<int>& boxes) {
    int n = boxes.size();
    // vector<vector<vector<int > > > dp(n + 1, vector<vector<int> >(n + 1, vector<int>(n + 1, 0)));
    return solve(0, n - 1, 0, boxes);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << removeBoxes(arr) << endl;
}
 
