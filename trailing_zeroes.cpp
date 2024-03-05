#include <iostream>
using namespace std;

int main(void) {
    long n, current = 5, ans = 0;
    cin >> n;
    while(current <= n) {
        ans += n / current;
        current *= 5;
    }
    cout << ans << endl;
}