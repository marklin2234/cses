#include <iostream>

int main(void) {
    int n;
    std::cin >> n;
     /*
     We can put even numbers together and odd numbers together
     */
    if (n > 1 && n <= 3) {
        std::cout << "NO SOLUTION";
        return 0;
    }

    int arr[n];
    int evenIdx = 0, oddIdx = n / 2;

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            arr[evenIdx++] = i;
        } else {
            arr[oddIdx++] = i;
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
}