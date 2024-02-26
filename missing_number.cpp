#include <iostream>

int main(void) {
    long n;
    std::cin >> n;

    long target = n * (n + 1) / 2;
    for (int i = 0; i < n - 1; i++) {
        int in;
        std::cin >> in;
        target -= in;
    }
    std::cout << target;
}