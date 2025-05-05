#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
vector<bool> visited, finished;
int cnt;

void dfs(int node) {
    visited[node] = true;
    int next = v[node];

    if (!visited[next]) {
        dfs(next);
    } else if (!finished[next]) {
        // 사이클 발생: next부터 node까지 카운트
        for (int i = next; i != node; i = v[i]) {
            cnt++;
        }
        cnt++; // 마지막 node 자신도 포함
    }

    finished[node] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        v = vector<int>(N + 1);
        visited = vector<bool>(N + 1, false);
        finished = vector<bool>(N + 1, false);
        cnt = 0;

        for (int i = 1; i <= N; i++) {
            cin >> v[i];
        }

        for (int i = 1; i <= N; i++) {
            if (!visited[i]) dfs(i);
        }

        cout << N - cnt << '\n';  // 전체 학생 - 사이클 포함 학생
    }

    return 0;
}
