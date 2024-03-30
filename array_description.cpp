#include <iostream>
#include <vector>
#include <algorithm>

#define MOD (int) 1e9 + 7

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<int> x(n);
    for (int i = 0; i < n; i++) cin >> x[i];

    vector<vector<int>> dp(n, vector<int>(m + 1, 0));
    if (x[0] == 0) {
        fill(dp[0].begin(), dp[0].end(), 1);
    } else {
        dp[0][x[0]] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (x[i] == 0) {
            for (int j = 1; j <= m; j++) {
                for (int k : { j - 1, j, j + 1 }) {
                    if (k >= 1 && k <= m) {
                        dp[i][j] += dp[i - 1][k];
                        dp[i][j] %= MOD;
                    }
                }    
            }
        } else {
            for (int k : { x[i] - 1, x[i], x[i] + 1 }) {
                if (k >= 1 && k <= m) {
                    dp[i][x[i]] += dp[i - 1][k];
                    dp[i][x[i]] %= MOD;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp[n - 1][i];
        ans %= MOD;
    }
    cout << ans << endl;
}
