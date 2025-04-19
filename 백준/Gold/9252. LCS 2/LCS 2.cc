#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.length();
    int len2 = s2.length();

    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));

    // DP 테이블 채우기
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // 문자가 같으면 이전까지의 LCS + 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // 다르면 둘 중 큰 값을 선택
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // LCS 문자열 복원 (역추적)
    string lcs = "";
    int i = len1, j = len2;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            // 같은 문자는 LCS에 포함
            lcs += s1[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // 출력
    reverse(lcs.begin(), lcs.end());
    cout << dp[len1][len2] << '\n';
    if (!lcs.empty()) {
        cout << lcs << '\n';
    }

    return 0;
}
