#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++) q.push(i);

    bool flag = true;
    while(!q.empty()) {
        int top = q.front();
        q.pop();
        if (flag) q.push(top);
        else cout << top << " ";
        flag = !flag;
    }
}
