#include <iostream>

using namespace std;

void solve(int n, int from, int to, int e) {
    if (n == 0) return;
    solve(n - 1, from, e, to);
    cout << from << " " << to << endl;
    solve(n - 1, e, to, from);
}

int main(void) {
    int n;
    cin >> n;
    cout << (1 << n) - 1 << endl;
    solve(n, 1, 3, 2);
}
