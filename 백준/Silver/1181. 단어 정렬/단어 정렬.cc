#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    set<string> unique_words; // 중복 제거와 사전 순 정렬을 위한 set

    // 단어 입력
    for (int i = 0; i < N; i++) {
        string word;
        cin >> word;
        unique_words.insert(word); // 중복 제거
    }

    // set을 vector로 변환
    vector<string> words(unique_words.begin(), unique_words.end());

    // 길이 -> 사전 순 정렬
    sort(words.begin(), words.end(), [](const string& a, const string& b) {
        if (a.length() != b.length()) {
            return a.length() < b.length(); // 길이 기준 정렬
        }
        return a < b; // 길이가 같으면 사전 순 정렬
    });

    // 결과 출력
    for (const auto& word : words) {
        cout << word << '\n';
    }

    return 0;
}