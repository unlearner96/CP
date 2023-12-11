#include <bits/stdc++.h>

using namespace std;

const int R = 7;
const int C = 7;

string s;

int ans{0};
vector<vector<bool>> vis(R, vector<bool>(C, false));

bool e(int x, int y) {
  return x >= 0 && x < R && y >= 0 && y < C && !vis[x][y];
}

void dfs(int idx = 0, int x = 0, int y = 0) {
  if (x == R - 1 && y == 0) {
    if (idx == R * C - 1) {
      ans++;
    }

    return;
  }

  vis[x][y] = true;

  if (s[idx] == '?' || s[idx] == 'L') {
    if (y - 1 >= 0 && !vis[x][y - 1]) {
      if (!(!e(x, y - 2) && e(x + 1, y - 1) && e(x - 1, y - 1))) {
        dfs(idx + 1, x, y - 1);
      }
    }
  }
  if (s[idx] == '?' || s[idx] == 'R') {
    if (y + 1 < C && !vis[x][y + 1]) {
      if (!(!e(x, y + 2) && e(x + 1, y + 1) && e(x - 1, y + 1))) {
        dfs(idx + 1, x, y + 1);
      }
    }
  }
  if (s[idx] == '?' || s[idx] == 'U') {
    if (x - 1 >= 0 && !vis[x - 1][y]) {
      if (!(!e(x - 2, y) && e(x - 1, y + 1) && e(x - 1, y - 1))) {
        dfs(idx + 1, x - 1, y);
      }
    }
  }
  if (s[idx] == '?' || s[idx] == 'D') {
    if (x + 1 < R && !vis[x + 1][y]) {
      if (!(!e(x + 2, y) && e(x + 1, y + 1) && e(x + 1, y - 1))) {
        dfs(idx + 1, x + 1, y);
      }
    }
  }

  vis[x][y] = false;
}

int main() {
  cin >> s;

  dfs();
  cout << ans;
}
