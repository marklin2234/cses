#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> dp;
    // dp[i] represents the minimum ending value of an increasing subsequence of length i
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) {
           dp.push_back(x); 
        } else {
            *it = x;
        }
    }
    cout << dp.size() << endl;
}
