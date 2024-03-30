#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(void) {
    int x, n;
    cin >> x >> n;
    // I want to add the things in reverse
    vector<int> lights(n);
    for (int i = 0; i < n; i++) cin >> lights[i];

    set<int> pos = { 0, x };
    for (int i = 0; i < n; i++) {
        pos.insert(lights[i]);
    }
    vector<int> ans(n);
    int prev = 0;
    int max = 0;
    for (int p : pos) {
        max = std::max(p - prev, max);
        prev = p;
    }
    ans.back() = max;

    for (int i = n - 1; i > 0; i--) {
        pos.erase(lights[i]);
        auto it = upper_bound(pos.begin(), pos.end(), lights[i]);
        auto it2 = it;
        it2--;
        max = std::max(max, *it - *it2);
        ans[i - 1] = max;
    }
    for (int i : ans) cout << i << " ";
    cout << endl;
}
