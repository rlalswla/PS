#include <vector>
#include <string>
#include <iostream>
#include <cstring>

using namespace std;

string s1, s2;
int memo[1001][1001]; // 메모이제이션 배열

// 재귀 함수를 통한 LCS 계산
int lcs(int i, int j) {
    // 기저 사례: 둘 중 하나의 문자열이 끝나면 LCS는 0
    if (i == 0 || j == 0) return 0;
    
    // 이미 계산된 값이 있으면 반환
    if (memo[i][j] != -1) return memo[i][j];
    
    // 현재 문자가 같으면 LCS 길이 증가
    if (s1[i-1] == s2[j-1])
        return memo[i][j] = lcs(i-1, j-1) + 1;
    
    // 문자가 다르면 둘 중 최대값 선택
    return memo[i][j] = max(lcs(i-1, j), lcs(i, j-1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s1 >> s2;
    
    // 메모이제이션 배열 초기화
    memset(memo, -1, sizeof(memo));
    
    cout << lcs(s1.length(), s2.length()) << '\n';
    
    return 0;
}