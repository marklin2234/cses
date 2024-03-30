#include <iostream>
#include <string>
#include <algorithm>

#define MOD (int) 1e9 + 7

using namespace std;

int main(void) {
    int n;
    cin >> n;
    string s;
    int dp[n][n];
    for (int i = 0; i < n; i++) fill(dp[i], dp[i] + n, 0);

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> s;
        if (i == 0 && s[0] == '*') dp[0][0] = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '*') continue;

            if (i > 0) {
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }

            if (j > 0) {
                dp[i][j] += dp[i][j - 1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout << dp[n - 1][n - 1] << endl;
}
