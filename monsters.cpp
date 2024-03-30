#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <queue>

#define pii pair<int, int>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    char map[n][m];
    pii start;
    queue<pii> q;
    vector<vector<int>> m_dist(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'A') {
                start.first = i;
                start.second = j;
            } else if (map[i][j] == 'M') {
                q.push(make_pair(i, j));
                m_dist[i][j] = 0;
            }
        }
    }
    
    int step = 1;
    int directions[4][2] = {{ 1, 0 }, { -1, 0 } , { 0, 1 }, {0, -1}};
    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            pii curr = q.front();
            q.pop();
            for (int (&d)[2] : directions) {
                int r = d[0] + curr.first, c = d[1] + curr.second;
                if (r < 0 || r >= n || c < 0 || c >= m) continue;
                if (m_dist[r][c] != INT_MAX || map[r][c] == '#') continue;

                m_dist[r][c] = step;
                q.push(make_pair(r, c));
            }
        }
        step++;
    }

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    vector<vector<int>> prev(n, vector<int>(m, '\0'));
    string turn = "DURL";

    q.push(start);
    dist[start.first][start.second] = 0;
    step = 1;

    while(!q.empty()) {
        int size = q.size();
        while(size--) {
            pii curr = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int (&d)[2] = directions[i];
                int r = d[0] + curr.first, c = d[1] + curr.second;
                if (r < 0 || r >= n || c < 0 || c >= m) continue;
                if (m_dist[r][c] <= step || map[r][c] == '#' || dist[r][c] != INT_MAX) continue;

                dist[r][c] = step;
                q.push(make_pair(r, c));
                prev[r][c] = i;
            }
        }
        step++;
    }
    pii end;
    for (int i = 0; i < n; i++) {
        if (dist[i][0] != INT_MAX) {
            end.first = i;
            end.second = 0;
        }
        if (dist[i][m - 1] != INT_MAX) {
            end.first = i;
            end.second = m - 1;
        }
    }
    for (int i = 0; i < m; i++) {
        if (dist[0][i] != INT_MAX) {
            end.first = 0;
            end.second = i;
        }
        if (dist[n - 1][i] != INT_MAX) {
            end.first = n - 1;
            end.second = i;
        }
    }
    // cout << end.first << " " << end.second << endl;
    vector<char> steps;
    while(end != start) {
        int i = end.first, j = end.second;
        if (dist[i][j] == INT_MAX) {
            cout << "NO" << endl;
            return 0;
        }
        steps.push_back(turn[prev[i][j]]);
        // cout << turn[prev[i][j]] << endl;
        end.first = i - directions[prev[i][j]][0];
        end.second = j - directions[prev[i][j]][1];
    }
    cout << "YES\n" << steps.size() << "\n";
    reverse(steps.begin(), steps.end());

    for (char c : steps) cout << c;
}
