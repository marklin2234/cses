#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;

    int h[n], s[n];

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<int> dp(x + 1, 0);
    
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= 0; j--) {
            if (j - h[i] < 0) continue;

            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
        }
    }
    cout << dp[x] << endl;
}
