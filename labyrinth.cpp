#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int main(void) {
  int n, m;
  cin >> n >> m;

  char map[n][m], prevStep[n][m];
  pair<int, int> start, end;
  int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  char turn[4] = {'D', 'U', 'R', 'L'};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
      if (map[i][j] == 'A') {
        start.first = i;
        start.second = j;
      } else if (map[i][j] == 'B') {
        end.first = i;
        end.second = j;
      }
    }
  }
  queue<pair<int, int>> q;
  q.push(start);
  bool vis[n][m];
  for (int i = 0; i < n; i++)
    fill(vis[i], vis[i] + m, false);
  vis[start.first][start.second] = true;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    int i = p.first, j = p.second;
    for (int l = 0; l < 4; l++) {
      int(&d)[2] = directions[l];
      int r = i + d[0], c = j + d[1];
      if (r < 0 || r >= n || c < 0 || c >= m)
        continue;
      if (map[r][c] == '#' || vis[r][c])
        continue;

      vis[r][c] = true;
      prevStep[r][c] = l;
      q.push(make_pair(r, c));
    }
  }
  if (vis[end.first][end.second]) {
    cout << "YES" << endl;
    vector<char> steps;
    while (end != start) {
      int p = prevStep[end.first][end.second];
      steps.push_back(p);
      end = make_pair(end.first - directions[p][0],
                      end.second - directions[p][1]);
    }
    reverse(steps.begin(), steps.end());
    cout << steps.size() << endl;

    for (int i : steps)
      cout << turn[i];
    cout << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
