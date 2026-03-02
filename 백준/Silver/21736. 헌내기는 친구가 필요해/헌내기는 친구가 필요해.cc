#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int N,M;
    cin >> N >> M;

    vector<vector<char>> v(N,vector<char>(M));
    
    vector<vector<bool>> visited(N,vector<bool>(M,false));
    int X,Y;
    int ans = 0;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> v[i][j] ;
            if(v[i][j] == 'I') {
                Y = i;
                X = j;
            }
        }
    }

    queue<pair<int,int>> q;

    q.push({Y,X});
    visited[Y][X] = true;

    int dx [] = {1,0,-1,0};
    int dy [] = {0,1,0,-1};

    while(!q.empty()){
        auto [y,x] = q.front();
        
        q.pop();
        for(int i = 0 ; i < 4 ; i++){
            if(y+dy[i] < 0 || y+dy[i] >= N  || x+dx[i] <0 || x+dx[i] >= M || visited[y+dy[i]][x+dx[i]] == true) continue;
            if(v[y+dy[i]][x+dx[i]] == 'O') {
                q.push({y+dy[i] , x+dx[i]});
                visited[y+dy[i]][x+dx[i]] = true;
            }
            if(v[y+dy[i]][x+dx[i]] == 'P') {
                q.push({y+dy[i] , x+dx[i]});
                visited[y+dy[i]][x+dx[i]] = true;
                ans++;
            }        
        }
    }
    if(ans == 0 ) {
        cout << "TT" ;
        return 0 ;
    }

    cout << ans;
    


    
    


    return 0;
}