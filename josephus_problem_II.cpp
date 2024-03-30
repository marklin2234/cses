#include <iostream>
#include <iterator>
#include <set>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    set<int> s;
    for (int i = 0; i < n; i++) s.insert(i + 1);
    int idx = 0;
    while(s.size() > 0) {
        (idx += k) %= s.size();
        auto it = s.begin();
        advance(it, idx);
        cout << *it << " ";
        s.erase(it);
    }
}
