#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    long curr = 0, ans = LONG_MIN;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        curr += x;
        ans = max(ans, curr);
        if (curr < 0) {
            curr = 0;
        }
    }
    cout << ans << endl;
}
