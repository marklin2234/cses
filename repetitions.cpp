#include <iostream>
#include <string>
#include <algorithm>

int main(void) {
    std::string s;

    std::cin >> s;

    int cnt = 0, max = 0;
    char curr = '\0';
    for (int i = 0; i < s.length(); i++) {
        if (curr != s[i]) {
            max = std::max(max, cnt);
            cnt = 0;
            curr = s[i];
        }
        cnt++;
    }
    max = std::max(max, cnt);
    std::cout << max;
}