#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    string n, m;
    getline(cin, n);
    getline(cin, m);

    int dp[n.size() + 1][m.size() + 1];

    for (size_t i = 0; i <= n.size(); i++) {
        dp[i][0] = i;
    }
    for (size_t i = 0; i <= m.size(); i++) {
        dp[0][i] = i;
    }

    for (size_t i = 1; i <= n.size(); i++) {
        for (size_t j = 1; j <= m.size(); j++) {
            if (n[i-1] == m[j-1]) dp[i][j] = dp[i - 1][j - 1];
            else dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
        }
    }   
    cout << dp[n.size()][m.size()] << endl;
}

