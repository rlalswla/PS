#include <iostream>
#include <vector>
#include <numeric>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> mem(N);
    vector<int> cost(N);

    for (int &x : mem) cin >> x;
    for (int &x : cost) cin >> x;

    int maxCost = accumulate(cost.begin(), cost.end(), 0);
    vector<int> dp(maxCost + 1, 0); // dp[i] = i 비용일 때 최대 메모리

    int answer = INT_MAX;

    for (int i = 0; i < N; ++i) {
        for (int j = maxCost; j >= cost[i]; --j) {
            dp[j] = max(dp[j], dp[j - cost[i]] + mem[i]);
            if (dp[j] >= M) {
                answer = min(answer, j); // 조기 조건 달성
            }
        }
    }

    cout << answer << '\n';
    return 0;
}
