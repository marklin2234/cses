#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string n;
    getline(cin, n);
    int freq[26] = { 0 };
    for (int i = 0; i < n.length(); i++) {
        freq[n[i] - 'A']++;
    }
    string odd = "";
    string ans = "";
    for (int i = 0; i < 26; i++) {
        if ((freq[i] & 1) == 1) {
            if (odd != "") {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
            while(freq[i]-- > 0) odd += i + 'A';
        } else {
            int target = freq[i] / 2;
            while(freq[i]-- > target) {
                ans += i + 'A';
                // cout << freq[i] << " " << target << endl;
            }
        }
    }
    string rans = "";
    for (int i = ans.length() - 1; i >= 0; i--) {
        rans += ans[i];
    }
    cout << ans << odd << rans << endl;
}