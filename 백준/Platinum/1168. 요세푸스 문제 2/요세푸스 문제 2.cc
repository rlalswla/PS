#include <iostream>
#include <vector>
using namespace std;

// 세그먼트 트리: 각 구간에 살아있는 사람 수를 저장
vector<int> tree;

// 세그먼트 트리 초기화
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = 1; // 모든 사람이 처음에는 살아있음
        return;
    }
    
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build(node*2+1, mid+1, end);
    
    // 부모 노드는 자식 노드들의 합
    tree[node] = tree[node*2] + tree[node*2+1];
}

// 특정 위치의 사람을 제거 (0으로 표시)
void update(int node, int start, int end, int pos) {
    if (pos < start || pos > end) return;
    
    if (start == end) {
        tree[node] = 0; // 해당 위치의 사람 제거
        return;
    }
    
    int mid = (start + end) / 2;
    update(node*2, start, mid, pos);
    update(node*2+1, mid+1, end, pos);
    
    // 부모 노드 업데이트
    tree[node] = tree[node*2] + tree[node*2+1];
}

// k번째 살아있는 사람 찾기
int query(int node, int start, int end, int k) {
    // 리프 노드에 도달: 해당 위치 반환
    if (start == end) return start;
    
    int mid = (start + end) / 2;
    int left_count = tree[node*2]; // 왼쪽 자식에 살아있는 사람 수
    
    if (k <= left_count) {
        // 왼쪽 서브트리에서 k번째 사람 찾기
        return query(node*2, start, mid, k);
    } else {
        // 오른쪽 서브트리에서 (k - left_count)번째 사람 찾기
        return query(node*2+1, mid+1, end, k - left_count);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, K;
    cin >> N >> K;
    
    // 세그먼트 트리 크기 설정 (약 4*N)
    tree.resize(4*N);
    build(1, 1, N);
    
    vector<int> result;
    int current_pos = 1; // 현재 위치 (처음은 1번 사람부터)
    
    for (int i = 0; i < N; i++) {
        int alive = tree[1]; // 현재 살아있는 사람 수
        
        // 다음 제거할 사람의 위치 계산
        current_pos = ((current_pos - 1) + K) % alive;
        if (current_pos == 0) current_pos = alive; // 나머지가 0이면 마지막 사람
        
        // current_pos번째 살아있는 사람 찾기
        int person = query(1, 1, N, current_pos);
        result.push_back(person);
        
        // 해당 사람 제거
        update(1, 1, N, person);
    }
    
    // 결과 출력
    cout << "<";
    for (int i = 0; i < N; i++) {
        cout << result[i];
        if (i < N-1) cout << ", ";
    }
    cout << ">" << endl;
    
    return 0;
}