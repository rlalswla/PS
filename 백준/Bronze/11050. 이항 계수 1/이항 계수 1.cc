#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

// 조합 계산 함수
unsigned long long combination(int n, int k) {
    if (k == 0 || k == n) return 1;
    if (k > n - k) k = n - k; // 더 작은 k 사용하여 계산 최적화
    
    unsigned long long result = 1;
    
    for (int i = 1; i <= k; i++) {
        result *= (n - (i - 1));
        result /= i;
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a, b; 
    cin >> a >> b;
    
    // 조합 계산: a C b
    unsigned long long ans = combination(a, b);
    
    cout << ans << endl;

    return 0;
}