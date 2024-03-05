#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long ans = 1e9 + 7;
void findMin(long &a, long &b, vector<int> &p, size_t i) {
    if (i == p.size()) {
        ans = min(ans, abs(a - b));
        return;
    }

    a += p[i];
    findMin(a, b, p, i + 1);
    a -= p[i];
    b += p[i];
    findMin(a, b, p, i + 1);
    b -= p[i];
}

int main(void) {
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    long a = 0, b = 0;
    findMin(a, b, p, 0);
    cout << ans << endl;
}
