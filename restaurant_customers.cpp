#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<vector<int>> times(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        times[i] = { a, b };
    }
    sort(times.begin(), times.end(), [](const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    });

    int ans = 0; 
    for (int i = 0; i < n; i++) {
        while (!pq.empty() && pq.top() < times[i][0]) {
            pq.pop();
        }
        pq.push(times[i][1]);
        ans = max(ans, (int) pq.size());
    }
    cout << ans << endl;
}
