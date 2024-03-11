#include <iostream>
#include <set>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    
    multiset<int> tickets;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        tickets.insert(p);
    }
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        auto find = tickets.upper_bound(t);

        if (find == tickets.begin()) {
            cout << -1 << endl;
        } else {
            cout << *(--find) << endl;
            tickets.erase(find);
        }
    }
}
