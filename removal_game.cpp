#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    long sum = 0;
    cin >> n;
    vector<long> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }
    vector<vector<long>> dp(n, vector<long>(n));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            if (i == j) dp[i][j] = x[i];
            else {
                dp[i][j] = max(x[i] - dp[i + 1][j], x[j] - dp[i][j - 1]);
            }
        }
    }
    cout << (dp[0][n - 1] + sum)/2 << endl;
}
