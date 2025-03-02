#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int rows, cols;
    cin >> cols >> rows;
    vector<vector<int>> v(rows, vector<int> (cols));
    

    
    for(int i = 0 ; i < rows; i++){
        for(int j = 0 ; j < cols ; j ++){
            cin>>v[i][j];
        }
    }
    

    queue<pair<int,int>> q;
    vector<vector<int>> ans(rows, vector<int> (cols , -1));
    

    for(int i = 0 ; i < rows; i++){
        for(int j = 0 ; j < cols ; j ++){
            if(v[i][j] == 1){
                q.push(make_pair(i,j));
                ans[i][j] = 0;

            }
            if(v[i][j] == -1){
                ans[i][j] = -1;
            }
        }
    }

    int dx[] = {0,0,1,-1};
    int dy[] = {1,-1,0,0};

    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];

            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && ans[nx][ny] == -1 && v[nx][ny] == 0) {
                q.push(make_pair(nx, ny));
                ans[nx][ny] = ans[a][b] + 1;
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            
            if (v[i][j] == 0 && ans[i][j] == -1) {
                
                cout << -1 << '\n';
                return 0;
            }
            answer = max(answer, ans[i][j]);
        }
    }

    cout << answer << '\n';
    

    return 0;
}