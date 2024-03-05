#include <iostream>
#include <string>
#include <set>

using namespace std;

void createString(string &n, string &s, int i, set<string> &vis, int target) {
    if (i == target) {
        if (!vis.contains(s)) {
            vis.insert(s);
        }
        return;
    }
    int len = n.length();
    for (int l = 0; l < len; l++) {
        char c = n[l];
        s.push_back(c);
        n.erase(l, 1);
        createString(n, s, i + 1, vis, target);
        n.insert(l, 1, c);
        s.pop_back();
    }
}

int main(void) {
    string n, s;
    getline(cin, n);
    set<string> vis;
    createString(n, s, 0, vis, n.length());
    cout << vis.size() << endl;
    for (string s : vis) {
        cout << s << endl;
    }
}