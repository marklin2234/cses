#include <iostream>
#include <algorithm>

int main(void) {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        long y, x;
        std::cin >> y;
        std::cin >> x;

        /*
        Lies on the border of max(x, y) square
        if even, the vertical is decreasing and horizontal is increasing
        if odd, the vertical is increasing and horizontal is decreasing
        */

        long size = std::max(x, y);
        long num = (size - 1) * (size - 1);
        if (size % 2 == 0) {
            num += std::min(y, size);
            if (y == size) {
                num += size - x;
            }
        } else {
            num += std::min(x, size);
            if (x == size) {
                num += size - y;
            }
        }
        std::cout << num << std::endl;
    }
}