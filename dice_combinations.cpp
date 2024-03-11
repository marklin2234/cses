#include <iostream>
#include <unordered_map>

using namespace std;

int MOD = (int) 1e9 + 7;
unordered_map<int, int> dp;

int dfs(int n) {
    if (n <= 0) {
        return n == 0;
    } else if (dp.contains(n)) return dp[n];

    for (int i = 1; i <= 6; i++) {
        dp[n] += dfs(n - i);
        dp[n] %= MOD;
    }
    return dp[n] % MOD;
}

int main(void) {
    int n;
    cin >> n;
    cout << dfs(n) << endl;
}
