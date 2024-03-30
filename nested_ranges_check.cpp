#include <algorithm>
#include <cstdint>
#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <climits>

#define pii pair<int, int>

using namespace std;

struct phash {
    template<class T1, class T2>
    uint64_t operator() (const pair<T1, T2> &p) const {
        return ((uint64_t) p.first << 32) | p.second;
    }
};

int main(void) {
    int n;
    cin >> n;

    auto cmp = [](const pii &a, const pii &b) {
        if (a.first == b.first) return a.second > b.second;
        else return a.first < b.first;
    };

    vector<pii> ranges(n);
    unordered_map<pii, int, phash> map;
    map.reserve(1024);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pii range = make_pair(x, y);
        ranges[i] = range;
        map.insert({ range, i});
    }

    sort(ranges.begin(), ranges.end(), cmp);
    vector<int> contains(n, 0);
    int min_right = INT_MAX;
    for (int i = n - 1; i >= 0; i--) {
        int idx = map.at(ranges[i]);
        if (ranges[i].second >= min_right) contains[idx] = 1;
        min_right = min(min_right, ranges[i].second);
    }
    for (int i : contains) cout << i << " ";

    vector<int> contained(n, 0);
    int max_right = INT_MIN;
    for (int i = 0; i < n; i++) {
        int idx = map.at(ranges[i]);
        if (ranges[i].second <= max_right) contained[idx] = 1;
        max_right = max(max_right, ranges[i].second);
    }
    cout << endl;
    for (int i : contained) cout << i << " ";
}
