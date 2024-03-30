#include <iostream>
#include <vector>

#define MOD (int) 1e9 + 7

using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n), dp(x + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    for (int c : coins) {
        for (int t = 0; t <= x; t++) {
            if (t - c < 0) continue;

            dp[t] += dp[t - c];
            dp[t] %= MOD;
        }
    }
    cout << dp[x] << endl;
}
