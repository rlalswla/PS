#include <iostream>
#include <queue>
#include <cmath> // abs() 사용

using namespace std;

// 커스텀 비교 구조체
struct compare {
    bool operator()(int a, int b) {
        // 절댓값이 다르면 절댓값이 작은 순서대로 (최소 힙 형태)
        if (abs(a) != abs(b)) {
            return abs(a) > abs(b); 
        }
        // 절댓값이 같으면 실제 값이 작은 순서대로
        return a > b;
    }
};

int main() {
    // 입출력 속도 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 커스텀 비교 연산자를 적용한 우선순위 큐
    priority_queue<int, vector<int>, compare> pq;

    while (N--) {
        int x;
        cin >> x;

        if (x != 0) {
            pq.push(x);
        } else {
            if (pq.empty()) {
                cout << 0 << "\n";
            } else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }

    return 0;
}