#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> people;
    for (int i = 1; i <= N; i++) {
        people.push_back(i);
    }

    vector<int> result;
    int idx = 0;

    while (!people.empty()) {
        idx = (idx + K - 1) % people.size();  // K번째 사람
        result.push_back(people[idx]);        // 제거
        people.erase(people.begin() + idx);   // 벡터에서 제거
    }

    // 출력 형식에 맞게 출력
    cout << "<";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << ">\n";

    return 0;
}
