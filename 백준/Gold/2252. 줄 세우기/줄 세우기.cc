#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N , M ;
    cin >> N >> M;

    vector<vector<int>>graph(N+1);
    vector<int>inputDegree(N+1,0);
    vector<bool> visited(N+1,0);
    inputDegree[0] = -1;
    
    for(int i = 0 ; i < M ; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        inputDegree[b]++;
    }

    queue <int> q;
    for(int i = 1 ; i < N+1 ; i++){
        if(inputDegree[i] == 0 && visited[i] == false) {
            q.push(i);
            visited[i]= true;
            while(!q.empty()){
                int front = q.front();
                q.pop();
                cout << front << " ";
                for(auto it : graph[front]){
                    inputDegree[it]--;
                    if(inputDegree[it] == 0 && visited[it] == false){
                        q.push(it);
                        visited[it]= true;
                    }
                }
            }
        }
    }    
    return 0;
}
