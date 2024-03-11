#include <iostream>
#include <vector>

using namespace std;

void place_cube(vector<int> &t, int k) {
    int l = 0, r = t.size() - 1;

    while(l <= r) {
        int mid = (l  + r) / 2;
        if (t[mid] > k) r = mid - 1;
        else l = mid + 1;
    }
    if (l == (int) t.size()) t.push_back(k);
    t[l] = k;
}

int main(void) {
    int n;
    cin >> n;
    vector<int> t;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        place_cube(t, k);
    }
    cout << t.size() << endl;
}
