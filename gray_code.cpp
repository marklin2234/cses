#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> findGreyCode(int n) {
    if (n == 0) {
        return { "0" };
    } else if (n == 1) {
        return { "0", "1" };
    }

    vector<string> rec = findGreyCode(n - 1);
    vector<string> ans;
    for (int i = 0; i < rec.size(); i++) {
        string s = rec[i];
        ans.push_back("0" + s);
    }
    for (int i = rec.size() - 1; i >= 0; i--) {
        string s = rec[i];
        ans.push_back("1" + s);
    }
    return ans;
}

int main(void) {
    int n;
    cin >> n;

    vector<string> ans;
    ans = findGreyCode(n);
    for (auto s : ans) {
        cout << s << endl;
    }
}
