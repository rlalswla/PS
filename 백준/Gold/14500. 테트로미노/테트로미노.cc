#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int N;
int M;
int answer = 0;
bool visited[501][501];

void dfs(vector<vector<int>> &v, int x, int y, int depth, int sum){

    if (depth == 4) {
        answer = max(answer , sum);
        return;
    };
    
    

    for(int i = 0 ; i < 4 ; i++){
        if( x + dx[i] < 0 || x + dx[i] >= N) continue;
        if( y + dy[i] < 0 || y + dy[i] >= M) continue;
        if( visited[x+dx[i]][y+dy[i]]) continue;

        if(depth == 2){
            visited[x+dx[i]][y+dy[i]] = true;
            dfs(v, x  ,y , depth+1, sum + v[x+dx[i]][y+dy[i]]);
            visited[x+dx[i]][y+dy[i]] = false;
        }


        visited[x+dx[i]][y+dy[i]] = true;
        dfs(v, x + dx[i] ,y+dy[i] , depth+1, sum + v[x+dx[i]][y+dy[i]]);
        visited[x+dx[i]][y+dy[i]] = false;
    }
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    vector<vector<int>> v(N,vector<int>(M,0));


    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            cin >> v[i][j];
        }
    }

    int ans = 0;

    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            visited[i][j] = true;
            dfs(v,i,j,1,v[i][j]);
            visited[i][j] = false;
        }
    }

    cout << answer;
    
    

    return 0;
}