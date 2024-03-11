#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    int idx[n + 2], pos[n + 1];
    idx[0] = 0;
    idx[n + 1] = n + 1;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        idx[x] = i;
        pos[i] = x;
    }
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (idx[i - 1] > idx[i]) {
            ans++;
        } 
    }
 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        
        int c = pos[a], d = pos[b];
        if (idx[c - 1] <= idx[c] && idx[c - 1] > b) ans++;
        if (idx[c - 1] > idx[c] && idx[c - 1] <= b) ans--;
        if (idx[c + 1] < idx[c] && idx[c + 1] >= b) ans--;
        if (idx[c + 1] >= idx[c] && idx[c + 1] < b) ans++;
        
        idx[c] = b;

        if (idx[d - 1] <= idx[d] && idx[d - 1] > a) ans++;
        if (idx[d - 1] > idx[d] && idx[d - 1] <= a) ans--;
        if (idx[d + 1] < idx[d] && idx[d + 1] >= a) ans--;
        if (idx[d + 1] >= idx[d] && idx[d + 1] < a) ans++;
        idx[d] = a;
        swap(pos[a], pos[b]);
        cout << ans << endl;
    }
}
