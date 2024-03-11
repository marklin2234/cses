#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
    int n, x;
    cin >> n >> x;

    int p[n];
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    sort(p, p + n);

    int i = 0, j = n - 1, ans = 0;

    while(i <= j) {
        if (p[i] + p[j] <= x) {
            i++;
            j--;
        } else {
           j--; 
        }
        ans++;
    }
    cout << ans << endl;
}
