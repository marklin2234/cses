#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int idx[n];
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        idx[x - 1] = i;
    }
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (idx[i - 1] > idx[i]) {
            ans++;
        } 
    }
    cout << ans << endl;
}
