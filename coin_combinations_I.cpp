#include <iostream>
#include <vector>

# define MOD (int) 1e9 + 7

using namespace std;

int dfs(vector<int> &coins, vector<int> &dp, int x) {
    if (x <= 0) {
        return x == 0;
    }

    if (dp[x] >= 0) {
        return dp[x];
    }

    int ret = 0;
    for (int c : coins) {
        ret += dfs(coins, dp, x - c);
        ret %= MOD;
    }
    dp[x] = ret;
    return ret;
}

int main(void) {
    int n, x;
    cin >> n >> x;    
    vector<int> coins(n), dp(x + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    cout << dfs(coins, dp, x) << endl;
}
