#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(void) {
    int n, ans = 0;
    cin >> n;

    unordered_map<int, int> map;
    map.reserve(1024);
    int start = -1;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if (map.contains(k)) {
            start = max(start, map[k]);
        }
        ans = max(ans, i - start);
        map[k] = i;
    }
    cout << ans << endl;
}
