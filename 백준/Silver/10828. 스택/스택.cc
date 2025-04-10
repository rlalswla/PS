#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    stack<int> stk;

    for (int i = 0; i < N; i++) {
        string cmd;
        cin >> cmd;

        if (cmd == "push") {
            int x;
            cin >> x;
            stk.push(x);
        } 
        else if (cmd == "pop") {
            if (stk.empty()) {
                cout << -1 << '\n';
            } else {
                cout << stk.top() << '\n';
                stk.pop();
            }
        } 
        else if (cmd == "top") {
            if (stk.empty()) {
                cout << -1 << '\n';
            } else {
                cout << stk.top() << '\n';
            }
        } 
        else if (cmd == "size") {
            cout << stk.size() << '\n';
        } 
        else if (cmd == "empty") {
            cout << (stk.empty() ? 1 : 0) << '\n';
        }
    }

    return 0;
}
