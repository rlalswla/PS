#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

int N, M;
vector<int> dx = {1,0,0,-1};
vector<int> dy = {0,1,-1,0};

int bfs(vector<vector<int>> &map){
    vector<vector<vector<int>>> dist(N, vector<vector<int>>(M, vector<int>(2, -1)));

    queue<tuple<int,int,int>> q;
    q.push({0,0,0}); // row, col, 벽 부순 여부
    dist[0][0][0] = 1;

    while(!q.empty()){
        auto [x, y, broken] = q.front();
        q.pop();

        for(int d = 0; d < 4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

            // 이동 가능한 빈 칸
            if(map[nx][ny] == 0 && dist[nx][ny][broken] == -1){
                dist[nx][ny][broken] = dist[x][y][broken] + 1;
                q.push({nx, ny, broken});
            }

            // 벽을 만났고 아직 안 부쉈다면
            if(map[nx][ny] == 1 && broken == 0 && dist[nx][ny][1] == -1){
                dist[nx][ny][1] = dist[x][y][broken] + 1;
                q.push({nx, ny, 1});
            }
        }
    }

    int noBreak = dist[N-1][M-1][0];
    int broke = dist[N-1][M-1][1];

    if(noBreak == -1 && broke == -1) return -1;
    else if(noBreak == -1) return broke;
    else if(broke == -1) return noBreak;
    else return min(noBreak, broke);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M));

    for(int i = 0; i < N; i++){
        string row;
        cin >> row;
        for(int j = 0; j < M; j++){
            map[i][j] = row[j] - '0';
        }
    }

    cout << bfs(map);
    return 0;
}
