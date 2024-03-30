#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<bool> vis(n + 1, false);
  vector<int> prev(n + 1);
  queue<int> q;
  q.push(1);
  vis[1] = true;

  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (auto next : adj[curr]) {
      if (!vis[next]) {
        q.push(next);
        vis[next] = true;
        prev[next] = curr;
      }
    }
  }
  if (vis[n]) {
    vector<int> steps;
    int curr = n;
    while (curr != 1) {
      steps.push_back(curr);
      curr = prev[curr];
    }
    steps.push_back(1);
    cout << steps.size() << endl;
    reverse(steps.begin(), steps.end());
    for (int c : steps)
      cout << c << " ";
    cout << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
}
