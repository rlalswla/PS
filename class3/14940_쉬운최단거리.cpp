#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int rows, cols; // 세로, 가로
    int startrow = -1;
    int startcol = -1;

    cin >> rows >> cols;

    vector<vector<int>> v(rows, vector<int>(cols));
    vector<vector<int>> ans(rows, vector<int>(cols, -1));
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> v[i][j];
            if (v[i][j] == 2) {
                startrow = i;
                startcol = j;
            }
        }
    }

    if (startrow == -1 || startcol == -1) {
        // 시작점이 없는 경우
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        return 0;
    }

    queue<pair<int, int>> q;
    q.push({startrow, startcol});
    visited[startrow][startcol] = true;
    ans[startrow][startcol] = 0;

    int dx[] = {0, 0, -1, 1}; // 상하좌우 이동을 위한 배열
    int dy[] = {-1, 1, 0, 0};

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny] && v[nx][ny] != 0) {
                visited[nx][ny] = true;
                ans[nx][ny] = ans[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (v[i][j] == 0) {
                cout << 0 << " ";
            } else {
                cout << ans[i][j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}