#include <iostream>

int main(void) {
    int n;
    std::cin >> n;

    long ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= 2;
        ans %= (int) 1e9 + 7;
    }
    std::cout << ans;
}