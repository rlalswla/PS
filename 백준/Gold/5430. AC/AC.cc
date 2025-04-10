#include <iostream>
#include <deque>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        string p;
        int n;
        string arr_str;
        deque<int> dq;

        cin >> p;
        cin >> n;
        cin >> arr_str;

        // 입력 배열 파싱
        string num;
        stringstream ss(arr_str.substr(1, arr_str.size() - 2)); // '[' 와 ']' 제거
        while (getline(ss, num, ',')) {
            if (!num.empty())
                dq.push_back(stoi(num));
        }

        bool is_reversed = false;
        bool error = false;

        for (char cmd : p) {
            if (cmd == 'R') {
                is_reversed = !is_reversed;
            } else if (cmd == 'D') {
                if (dq.empty()) {
                    error = true;
                    break;
                }
                if (!is_reversed)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }

        if (error) {
            cout << "error\n";
        } else {
            cout << "[";
            while (!dq.empty()) {
                if (is_reversed) {
                    cout << dq.back();
                    dq.pop_back();
                } else {
                    cout << dq.front();
                    dq.pop_front();
                }
                if (!dq.empty())
                    cout << ",";
            }
            cout << "]\n";
        }
    }

    return 0;
}
