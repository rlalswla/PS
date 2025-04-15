#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

int N;
int maxdist = -1;
int maxVertex = -1;

void dfs(int startV, int dist, vector<vector<pair<int,int>>> &tree, vector<bool> &visited){

    if(dist > maxdist){
        maxdist = dist;
        maxVertex = startV;
    }
    

    for(auto it: tree[startV]){
        if(visited[it.first] == false){
            visited[it.first] = true;
            dfs(it.first, it.second + dist  , tree, visited);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<vector<pair<int,int>>> tree(N+1);

    for(int i = 0; i < N; i++){
        int startV;
        cin >> startV;
        while(1){
            int  destV, dist;
            cin >> destV;
            if(destV == -1) break;
            cin >> dist;
            tree[startV].push_back({destV, dist});
            tree[destV].push_back({startV, dist});
        }
    }


    vector<bool>visited(N+1, false);
    visited[1] = true;
    dfs(1, 0, tree, visited);
    
    visited = vector<bool>(N+1, false);
    maxdist = -1;
    visited[maxVertex] = true;
    dfs(maxVertex, 0, tree, visited);
    cout << maxdist << '\n';
    
    return 0;
}
