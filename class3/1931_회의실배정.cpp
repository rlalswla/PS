#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int>> meetings(N);

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        meetings[i] = make_pair(end, start); // 종료 시간을 먼저 저장
    }

    sort(meetings.begin(), meetings.end());

    int count = 0;
    int last_end_time = 0;

    for (int i = 0; i < N; i++) {
        int start = meetings[i].second;
        int end = meetings[i].first;

        if (start >= last_end_time) {
            count++;
            last_end_time = end;
        }
    }

    cout << count << '\n';

    return 0;
}