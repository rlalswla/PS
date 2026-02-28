#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

struct Tomato {
    //가로, 세로, 높이
    int z,y,x,day;
};

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int X,Y,Z;
    cin >> X >> Y >> Z;

    vector<vector<vector<int>>>graph(Z, vector<vector<int>>(Y, vector<int>(X, 0)));
    queue <Tomato> q;


    for (int i = 0; i < Z; i++) {
        for (int j = 0; j < Y; j++) {
            for (int k = 0; k < X; k++) {
                cin >> graph[i][j][k];
                if (graph[i][j][k] == 1) {
                    q.push({i, j, k, 0}); // 익은 토마토 큐에 삽입
                }
            }
        }
    }

    int dx[] = {-1,1,0,0,0,0};
    int dy[] = {0,0,-1,1,0,0};
    int dz[] = {0,0,0,0,1,-1};
    int lastday = -1;

    while(!q.empty()){
        Tomato curr = q.front();
        q.pop();
        lastday = curr.day;

        for(int i = 0 ; i < 6 ; i++){
            if(curr.x+dx[i] < 0 || curr.x+dx[i] >= X) continue;
            if(curr.y+dy[i] < 0 || curr.y+dy[i] >= Y) continue;
            if(curr.z+dz[i] < 0 || curr.z+dz[i] >= Z) continue;

            if(abs(graph[curr.z + dz[i]][curr.y+ dy[i]][curr.x+ dx[i]]) == 1){
                continue;
            }else{
                graph[curr.z+ dz[i]][curr.y+ dy[i]][curr.x+ dx[i]] = 1;
                q.push({curr.z+ dz[i], curr.y+ dy[i],curr.x+ dx[i], curr.day +1});
            }
        }
    }

    for(auto i : graph){
        for(auto j : i){
            for(auto k : j){
                if( k == 0){
                    cout << -1;
                    return 0;
                }
            }
        }
    }
    cout << lastday;
    return 0;
}