#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    sort(p, p + n);
    long target = p[n / 2], ans = 0;
    for (int i = 0; i < n; i++) {
        ans += abs(target - p[i]);
    }
    cout << ans << endl;
}
