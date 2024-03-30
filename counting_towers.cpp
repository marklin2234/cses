#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int main(void) {
    int t;
    std::cin >> t;

    std::vector<std::vector<long>> dp(1000001, std::vector<long>(2));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i < 1000001; i++) {
        dp[i][0] = ((dp[i-1][0] * 2 % MOD) + dp[i-1][1]) % MOD;
        dp[i][1] = (dp[i-1][0] + (dp[i-1][1] * 4 % MOD)) % MOD;
    }

    while(t--) {
        int n;
        std::cin >> n;
        std::cout << (dp[n][0] + dp[n][1]) % MOD << std::endl;
    }
}
