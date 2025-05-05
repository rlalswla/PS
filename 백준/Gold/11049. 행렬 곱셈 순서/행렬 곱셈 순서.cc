#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> matrix(N);
    for (int i = 0; i < N; ++i) {
        cin >> matrix[i].first >> matrix[i].second;
    }


    vector<vector<long long>> dp(N, vector<long long>(N, 0));

    for (int length = 2; length <= N; ++length) { 
        for (int i = 0; i <= N - length; ++i) {
            int j = i + length - 1;
            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; ++k) {
                long long cost = dp[i][k] + dp[k + 1][j]
                    + 1LL * matrix[i].first * matrix[k].second * matrix[j].second;

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[0][N - 1] << '\n';
    return 0;
}
