#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll MOD = 1'000'000'007;

using matrix = vector<vector<ll>>;

// 2x2 행렬 곱셈
matrix multiply(matrix &a, matrix &b) {
    matrix res(2, vector<ll>(2));
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % MOD;
    return res;
}

// 행렬 거듭제곱
matrix power(matrix base, ll exp) {
    matrix result = {{1, 0}, {0, 1}}; // 단위 행렬
    while (exp > 0) {
        if (exp % 2 == 1) result = multiply(result, base);
        base = multiply(base, base);
        exp /= 2;
    }
    return result;
}

int main() {
    ll n;
    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    matrix base = {{1, 1}, {1, 0}};
    matrix res = power(base, n - 1);
    cout << res[0][0] << '\n'; // F(n)
}
