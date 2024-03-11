#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int coins[n];
    for (int i = 0; i < n; i++) cin >> coins[i];
    sort(coins, coins + n);

    long ans = 1;
    for (int i = 0; i < n; i++) {
        if (coins[i] > ans) {
            cout << ans << endl;
            return 0;
        }
        ans = ans + coins[i];
    }
    cout << ans << endl;
}
