#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<vector<int>> times(n);
    for (int i = 0; i < n; i++) {
         int a, b;
         cin >> a >> b;
         times[i] = { a, b };
    }
    sort(times.begin(), times.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[1] < b[1];
    });
    int prev = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        if (times[i][0] >= prev) {
            ans++;
            prev = times[i][1];
        }
    }
    cout << ans << endl; 
}
