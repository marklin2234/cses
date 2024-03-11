#include <iostream>
#include <unordered_map>

using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;

    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a >= x) continue;
        else if (map.contains(x - a)) {
            cout << map[x - a] + 1 << " " << i + 1 << endl;
            return 0;
        }
        map[a] = i;
    }
    cout << "IMPOSSIBLE" << endl;
}
