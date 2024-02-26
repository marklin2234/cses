#include <iostream>

int main(void) {
    int n;
    std::cin >> n;

    for (long k = 1; k <= n; k++) {
        /*
        there are k^2 ways to put knight 1
        and k^2 - 1 ways to put knight 2
        numWays = k^2(k^2 - 1) / 2
        */
       std::cout << ((k * k)*(k * k - 1)) / 2 - 4*(k - 2)*(k - 1) << std::endl;
    }
}