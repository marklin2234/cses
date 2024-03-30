#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> dp(n + 1, (int) 1e9 + 7);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
       string s = to_string(i);
       for (char &c : s) {
           if (i - c + '0' < 0) continue;

           dp[i] = min(dp[i], dp[i - c + '0'] + 1);
       }
    }
    cout << dp[n] << endl;
}
