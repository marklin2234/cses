#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;
    
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    vector<int> dp(x + 1, (int) 1e9 + 7);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int c : coins) {
            if (i - c >= 0) dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
    cout << ((dp[x] == (int) 1e9 + 7) ? -1 : dp[x]) << endl;
}
