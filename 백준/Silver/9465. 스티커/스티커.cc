#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        int n;
        cin >> n;
        
        vector<vector<int>> stickers(2, vector<int>(n+1, 0)); // 1-indexed로 사용
        
        // 스티커 점수 입력
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> stickers[i][j];
            }
        }
        
        // DP 배열 초기화
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        
        // 첫 번째 열 초기화
        dp[0][1] = stickers[0][1];
        dp[1][1] = stickers[1][1];
        
        // DP 계산
        for (int j = 2; j <= n; j++) {
            dp[0][j] = max(dp[1][j-1], dp[1][j-2]) + stickers[0][j];
            dp[1][j] = max(dp[0][j-1], dp[0][j-2]) + stickers[1][j];
        }
        
        // 최대값 출력
        cout << max(dp[0][n], dp[1][n]) << '\n';
    }

    return 0;
}