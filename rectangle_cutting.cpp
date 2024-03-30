#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;

    int dp[a + 1][b + 1];
    // dp[i][j] represents the number of cuts for a ixj rectangle
    // we always cut the bigger piece into the size of the smaller piece, so we get a square.

   for (int i = 1; i <= a; i++) {
       for (int j = 1; j <= b; j++) {
           if (i == j) dp[i][j] = 0;
           else {
               dp[i][j] = 1e9;
               for (int l = 1; l < i; l++) {
                   dp[i][j] = min(dp[i][j], dp[i - l][j] + dp[l][j] + 1);
               }
               for (int l = 1; l < j; l++) {
                   dp[i][j] = min(dp[i][j], dp[i][j - l] + dp[i][l] + 1);
               }
           }
       }
   }
   cout << dp[a][b] << endl;
}
