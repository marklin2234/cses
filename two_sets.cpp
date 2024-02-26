#include <iostream>
#include <vector>

int main(void) {
    int n;
    std::cin >> n;

    long target = n * (n + 1) / 2;
    if (target % 2 != 0) {
        std::cout << "NO";
        return 0;
    }

    int cnt = 1, start = 1;
    bool t = true;
    std::vector<int> a, b;
    if (n % 4 == 3) {
        a.push_back(1);
        a.push_back(2);
        b.push_back(3);
        start = 4;
    }
    for (int i = start; i <= n; i++) {
        if (t) {
            a.push_back(i);
        } else {
            b.push_back(i);
        }
        if (++cnt == 2) {
            cnt = 0;
            t = !t;
        }
    }
    std::cout << "YES" << std::endl;
    std::cout << a.size() << std::endl;
    for (size_t i = 0; i < a.size(); i++) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl << b.size() << std::endl;
    for (size_t i = 0; i < b.size(); i++) {
        std::cout << b[i] << " ";
    }
}