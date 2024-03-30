#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(void) {
    int n, maxSum = 0;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        maxSum += coins[i];
    }

    vector<vector<bool>> dp(n + 1, vector<bool>(maxSum + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= maxSum; j++) {
            dp[i][j] = dp[i - 1][j];
            int prev = j - coins[i - 1];
            if (prev >= 0 && dp[i - 1][prev]) {
                dp[i][j] = true;
            }
        }
    }
    vector<int> out;
    for (int i = 1; i <= maxSum; i++) {
        if (dp[n][i]) out.push_back(i);
    }
    cout << out.size() << endl;
    for (int i : out) {
        cout << i << " ";
    } 
}
