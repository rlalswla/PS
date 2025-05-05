#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;


vector<vector<int>> graph;
int start;
vector<bool> visited(1001,false);

void dfs(int index){
    cout << index << " ";
    visited[index] = true;
    for(auto it : graph[index]){
        if(visited[it] == false){
            dfs(it);
        }
    }
}

void bfs(){
    queue<int> q;
    q.push(start);
    fill(visited.begin(), visited.end(), false);
    visited[start]= true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout <<now << " ";        
        for(auto it : graph[now]){
            if(visited[it] == false){
                q.push(it);
                visited[it] = true;
            }
        }
    }
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N,M;
    cin >> N >> M >>start;
    
    graph.resize(N+1);

    for(int i = 0; i < M ; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i = 1; i < N+1 ; i++){
        if(graph[i].size() > 1){
            sort(graph[i].begin(), graph[i].end());
        }
    }

    dfs(start);
    cout << '\n';
    bfs();

    
    


    return 0;
}