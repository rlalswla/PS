#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Helper function to compute the prefix sum of the grid
vector<vector<int>> computePrefixSum(const vector<vector<int>>& grid, int N) {
    vector<vector<int>> prefixSum(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            prefixSum[i][j] = grid[i - 1][j - 1] +
                              prefixSum[i - 1][j] +
                              prefixSum[i][j - 1] -
                              prefixSum[i - 1][j - 1];
        }
    }
    return prefixSum;
}

// Function to check if there exists a KxK grid with sum > S
bool isValidK(int K, int N, int S, const vector<vector<int>>& prefixSum) {
    for (int i = K; i <= N; ++i) {
        for (int j = K; j <= N; ++j) {
            int totalSum = prefixSum[i][j]
                         - prefixSum[i - K][j]
                         - prefixSum[i][j - K]
                         + prefixSum[i - K][j - K];
            if (totalSum > S) {
                return true;
            }
        }
    }
    return false;
}

// Function to find the minimum K
int findMinimumK(int N, int S, const vector<vector<int>>& grid) {
    vector<vector<int>> prefixSum = computePrefixSum(grid, N);

    int left = 1, right = N, result = N + 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (isValidK(mid, N, S, prefixSum)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result > N ? -1 : result; // Return -1 if no valid K exists
}

int main() {
    int N, S;
    cin >> N >> S;
    vector<vector<int>> grid(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }

    int result = findMinimumK(N, S, grid);
    cout << result << endl;

    return 0;
}
