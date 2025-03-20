#include <vector>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    // N+1 크기로 초기화 (1-indexed 사용)
    vector<vector<int>> board(N+1, vector<int>(N+1, 0));
    vector<vector<int>> prefixSum(N+1, vector<int>(N+1, 0));

    // 배열 입력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
            // 누적합 계산
            prefixSum[i][j] = prefixSum[i-1][j] + prefixSum[i][j-1] - prefixSum[i-1][j-1] + board[i][j];
        }
    }

    // 쿼리 처리
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int result = prefixSum[x2][y2] - prefixSum[x2][y1-1] - prefixSum[x1-1][y2] + prefixSum[x1-1][y1-1];
        cout << result << '\n';
    }

    return 0;
}