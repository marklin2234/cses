#include <iostream>
#include <algorithm>

int main(void) {
    int n;
    std::cin >> n;
    int nums[n];
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;

        nums[i] = x;
    }
    std::sort(nums, nums + n);
    for (int i = 1; i < n; i++) {
        if (nums[i] != nums[i - 1]) cnt++;
    }
    std::cout << cnt;
}