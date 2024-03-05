#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;
    while(t-->0) {
        int a, b;
        cin >> a >> b;
        if ((a + b) % 3 == 0 &&
            (a / 2 <= b && b / 2 <= a)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}