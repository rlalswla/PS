#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

// 다익스트라 알고리즘으로 시작점에서 모든 노드까지의 최단 거리를 계산
vector<int> dijkstra(vector<vector<pair<int,int>>>& graph, int start, int n) {
    vector<int> dist(n+1, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while(!pq.empty()) {
        int current_dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        
        // 이미 처리된 노드는 건너뛰기
        if(current_dist > dist[current]) continue;
        
        // 인접한 노드들을 확인
        for(auto& edge : graph[current]) {
            int next = edge.first;
            int weight = edge.second;
            
            // 더 짧은 경로를 발견한 경우 업데이트
            if(dist[next] > dist[current] + weight) {
                dist[next] = dist[current] + weight;
                pq.push({dist[next], next});
            }
        }
    }
    
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    // 마을 수, 도로 수, 파티 장소
    int N, M, X;
    cin >> N >> M >> X;
    
    // 그래프 초기화
    vector<vector<pair<int,int>>> graph(N+1);
    vector<vector<pair<int,int>>> reverse_graph(N+1);
    
    // 도로 정보 입력
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});        // 정방향 그래프
        reverse_graph[b].push_back({a, c}); // 역방향 그래프
    }
    
    // X에서 각 마을로 가는 최단 거리 계산
    vector<int> dist_from_x = dijkstra(graph, X, N);
    
    // 각 마을에서 X로 가는 최단 거리 계산 (역방향 그래프 사용)
    vector<int> dist_to_x = dijkstra(reverse_graph, X, N);
    
    // 왕복 시간이 가장 긴 학생 찾기
    int max_round_trip = 0;
    for(int i = 1; i <= N; i++) {
        if(i != X) { // X는 제외 (필요하다면 포함 가능)
            int round_trip = dist_from_x[i] + dist_to_x[i];
            max_round_trip = max(max_round_trip, round_trip);
        }
    }
    
    cout << max_round_trip << '\n';
    
    return 0;
}