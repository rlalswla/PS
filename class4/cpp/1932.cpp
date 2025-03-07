#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int getMax(int row, int col, vector<vector<int>> &dp, vector<vector<int>> &tri, int N) {
    
    if (dp[row][col] != -10000) {
        return dp[row][col];
    }
    
    
    if (row == N - 1) {
        dp[row][col] = tri[row][col];
        return dp[row][col];
    }
    
    
    int leftPath = getMax(row + 1, col, dp, tri, N);
    int rightPath = getMax(row + 1, col + 1, dp, tri, N);
    
    
    dp[row][col] = tri[row][col] + max(leftPath, rightPath);
    
    return dp[row][col];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<vector<int>> tri(N, vector<int>(N));
    vector<vector<int>> dp(N, vector<int>(N, -10000));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> tri[i][j];
        }
    }

    // 재귀적으로 최대 경로 합 계산
    int ans = getMax(0, 0, dp, tri, N);
    cout << ans << '\n';


    return 0;
}