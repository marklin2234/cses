#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>> &map, vector<vector<bool>> &vis, int i, int j) {
  vis[i][j] = true;
  int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  for (int(&d)[2] : directions) {
    int r = i + d[0], c = j + d[1];
    if (r < 0 || r >= map.size() || c < 0 || c >= map[0].size())
      continue;
    if (map[r][c] == '#' || vis[r][c])
      continue;

    dfs(map, vis, r, c);
  }
}

int main(void) {
  int n, m;
  cin >> n >> m;

  vector<vector<char>> map(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vis[i][j])
        continue;
      if (map[i][j] == '.') {
        dfs(map, vis, i, j);
        count++;
      }
    }
  }
  cout << count << endl;
}
