#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <climits>
#include <cstring> 

using namespace std;

int max_dist = 0;
int farthest_node = 0;


void dfs1(vector<vector<pair<int,int>>> &tree, vector<bool> &visited, int node, int dist) {
    visited[node] = true;
    
    if(dist > max_dist) {
        max_dist = dist;
        farthest_node = node;
    }
    
    for(auto &edge : tree[node]) {
        int next = edge.first;
        int weight = edge.second;
        
        if(!visited[next]) {
            dfs1(tree, visited, next, dist + weight);
        }
    }
}

void dfs2(vector<vector<pair<int,int>>> &tree, vector<bool> &visited, int node, int dist) {
    visited[node] = true;
    
    max_dist = max(max_dist, dist);
    
    for(auto &edge : tree[node]) {
        int next = edge.first;
        int weight = edge.second;
        
        if(!visited[next]) {
            dfs2(tree, visited, next, dist + weight);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    if(N == 1) {  // 노드가 하나인 경우 지름은 0
        cout << 0 << '\n';
        return 0;
    }
    
    vector<vector<pair<int,int>>> tree(N+1);

    for(int i = 0; i < N-1; i++) {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        tree[parent].push_back({child, weight});
        tree[child].push_back({parent, weight});
    }
    
    vector<bool> visited(N+1, false);
    
    // 임의의 노드(1)에서 시작하여 가장 먼 노드 찾기
    max_dist = 0;
    dfs1(tree, visited, 1, 0);
    
    
    fill(visited.begin(), visited.end(), false);
    
    
    max_dist = 0;
    dfs2(tree, visited, farthest_node, 0);
    
    cout << max_dist << '\n';

    return 0;
}