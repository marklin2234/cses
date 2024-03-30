#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

int main(void) {
  int n, sum;
  const int MOD = 1e9 + 7;
  cin >> n;
  sum = n * (n + 1) / 2;
  if (sum % 2 == 1) {
    cout << 0 << endl;
    return 0;
  }
  sum /= 2;
  vector<vector<long>> dp(n, vector<long>(sum + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= sum; j++) {
      dp[i][j] = dp[i - 1][j];
      int left = j - i;
      if (left >= 0)
        (dp[i][j] += dp[i - 1][left]) %= MOD;
    }
  }
  cout << dp[n - 1][sum] << endl;
}
