#include <iostream>
#include <vector>

using namespace std;

int n, m;

void dfs(int curr, vector<vector<int>> &roads, vector<bool> &vis) {
  vis[curr] = true;
  for (auto next : roads[curr]) {
    if (!vis[next]) {
      dfs(next, roads, vis);
    }
  }
}
int main(void) {
  cin >> n >> m;
  vector<vector<int>> roads(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    roads[a].push_back(b);
    roads[b].push_back(a);
  }
  vector<bool> vis(n + 1, false);
  vector<int> cities;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, roads, vis);
      cities.push_back(i);
    }
  }
  cout << cities.size() - 1 << endl;
  for (size_t i = 1; i < cities.size(); i++) {
    cout << cities[i - 1] << " " << cities[i] << endl;
  }

  return 0;
}
