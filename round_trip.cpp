#include <iostream>
#include <stack>
#include <vector>

using namespace std;

bool check = false;
int n, m;

void dfs(int start, vector<bool> &vis, vector<vector<int>> &adj) {
    if (check) return;
    stack<int> s;
    s.push(start);
    vector<int> path, prev(n + 1, -1);
    while(!s.empty()) {
        if (check) return;
        int curr = s.top();
        s.pop();
        vis[curr] = true;
        prev[curr] = path.size();
        path.push_back(curr);
        
        for (int next : adj[curr]) {
            if (!vis[next]) s.push(next);
            else {
                if (prev[next] == -1) continue;

                if (path.size() - prev[next] >= 3) {
                    check = true;
                    cout << path.size() - prev[next] + 1 << endl;
                    for (int i = prev[next]; i < path.size(); i++) {
                        cout << path[i] << " ";
                    }
                    cout << path[prev[next]] << endl;
                }
            }
        }
    }
}

int main(void) {
    cin >> n >> m;
    vector<vector<int>> adj(n + 1, vector<int>());

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) dfs(i, vis, adj);
        if (check) break;
    }
    if (!check) cout << "IMPOSSIBLE" << endl;
}
