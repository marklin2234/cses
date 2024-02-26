#include <iostream>

int main(void) {
    int n;
    std::cin >> n;
    long moves = 0, prev = 0;
    for (size_t i = 0; i < n; i++) {
        long x;
        std::cin >> x;
        if (x < prev) {
            moves += prev - x;
        }
        if (x > prev) {
            prev = x;
        }
    }
    std::cout << moves;
}