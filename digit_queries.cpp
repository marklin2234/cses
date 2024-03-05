#include <iostream>
#include <string>

int main(void) {
    int q;
    std::cin >> q;

    while(q-->0) {
        long k;
        std::cin >> k;

        /*
        1-9 -> 10^1 - 10^0 numbers 9
        10 -> 99 -> 10^2 - 10^1 numbers 90 -> 180
        100 -> 999 -> 10^3 - 10^2 numbers 900 -> 1800
        1000 -> 9999 -> 9000 -> 18000
        */
        int digits = 1;
        long count = 9;
        long start = 1;
        while(k > count * digits) {
            k -= count * digits;
            digits++;
            count *= 10;
            start *= 10;
        }
        start += (k - 1) / digits;
        auto s = std::to_string(start);
        std::cout << s[(k - 1) % digits] << std::endl;
    }
}