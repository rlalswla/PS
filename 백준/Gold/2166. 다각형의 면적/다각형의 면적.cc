#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

typedef long long ll;

int main() {
    int N;
    cin >> N;

    vector<pair<ll, ll>> points(N);
    for (int i = 0; i < N; ++i) {
        cin >> points[i].first >> points[i].second;
    }

    ll sum1 = 0, sum2 = 0;

    for (int i = 0; i < N; ++i) {
        int next = (i + 1) % N;
        sum1 += points[i].first * points[next].second;
        sum2 += points[i].second * points[next].first;
    }

    double area = abs(sum1 - sum2) / 2.0;

    // 소수 첫째 자리까지 반올림
    cout << fixed << setprecision(1) << area << '\n';

    return 0;
}
