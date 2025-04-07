#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// 1. 특정 (i , j ) 에서 회전시키는 로직 ( 90, 180, 270 선택 가능)
    // 경우의수 9 * 3 = 27
// 2. 5 X 5 에서 유적 개수 뽑아내는 로직
    // 경우의수 = bfs
// 2.1 graph 복사한뒤 최대로 뽑아낼수 있는 회전 로직 찾아내고, 실제 원본에 적용 3번 시행시점에
// (2번에 flag 제공하고 개수 뽑으면서 삭제하면될둣?).
// 3. 빠진 유적에서 다시 벽면에 있는 유적으로 채워넣는 로직
    // 다시 2 번으로.
    // 없으면 종료. + 턴수 2.1 로 회귀

queue < int > treasureQ;

vector<vector<int>>  rotateOnce(int row , int col, vector<vector<int>> treasure){
    vector <vector<int>> treasureCopy = treasure;
    treasureCopy[row-1][col-1] = treasure[row+1][col-1];
    treasureCopy[row-1][col] =  treasure[row][col-1];
    treasureCopy[row-1][col+1] = treasure[row-1][col-1];
    treasureCopy[row][col-1] = treasure[row+1][col];
    treasureCopy[row][col+1] = treasure[row-1][col];
    treasureCopy[row+1][col-1] = treasure[row+1][col+1];
    treasureCopy[row+1][col] = treasure[row][col+1];
    treasureCopy[row+1][col+1] = treasure[row-1][col+1];
    return treasureCopy;
}

int bfs(vector<vector<int>> &treasure, bool isDelete){
    vector<vector<bool>> visited(5,vector<bool>(5, false));

    int cntAll = 0 ; 

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0 , 1 , 0, -1};


    vector<pair<int,int>> temp;

    for(int i = 0 ; i < 5 ; i ++){
        for(int j = 0 ; j < 5 ; j ++){
            if(visited[i][j] == true){
                continue;
            }
            
            queue<pair<int, int>> q;
            q.push({i,j});
            int goal = treasure[i][j];
            visited[i][j] = true;
            int cnt  = 0;


            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                temp.push_back({row,col});
                cnt ++;

                for(int dir = 0 ; dir < 4  ; dir++){
                    if(row+dx[dir] >= 0 && row+dx[dir] < 5 && col + dy[dir] >= 0 && col + dy[dir] < 5 && visited[row+dx[dir]][col+dy[dir]] == false && treasure[row+dx[dir]][col+dy[dir]] == goal){
                        q.push({row+dx[dir] , col+dy[dir]});
                        visited[row+dx[dir]][col+dy[dir]] = true;
                    }
                }
            }
            if(cnt >= 3){
                cntAll += cnt;
            } else{
                for(int idx = 0 ; idx < cnt ; idx++){
                    temp.pop_back();
                }
            }
        }
    }

    if(isDelete && cntAll != 0){
        sort(temp.begin(), temp.end(),[](auto a , auto b){
            if(a.second == b.second){
                return a.first > b.first;
            }
            return a.second < b.second;
        });

        // for(auto [r,c] : temp){
        //     cout << r << ' ' <<c <<' ';
        // }
        // cout << endl;

        for(auto it : temp){
            treasure[it.first][it.second] = treasureQ.front();
            treasureQ.pop();
        }
    }
    return cntAll;    
}

int rotationAndCheck(int degree, int row, int col, vector<vector<int>> &treasure){

    vector<vector<int>> rotationResult;

    switch (degree)
    {
    case 90:
        rotationResult = rotateOnce(row, col, treasure);

        break;
    case 180:
        rotationResult = rotateOnce(row,col , treasure);
        rotationResult = rotateOnce(row,col , rotationResult);
        break;
    case 270: 
        rotationResult = rotateOnce(row,col , treasure);
        rotationResult = rotateOnce(row,col , rotationResult);
        rotationResult = rotateOnce(row,col , rotationResult);
        break;
    default:
        break;
    }

    // for(auto i : rotationResult){
    //     for(auto j : i){
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    int res = bfs(rotationResult, false);
    return res;
}

void rotationAndDelete(int degree, int row , int col , vector<vector<int>> &treasure){
    switch (degree)
    {
    case 90:
        treasure = rotateOnce(row, col, treasure);

        break;
    case 180:
        treasure = rotateOnce(row,col , treasure);
        treasure = rotateOnce(row,col , treasure);
        break;
    case 270: 
        treasure = rotateOnce(row,col , treasure);
        treasure = rotateOnce(row,col , treasure);
        treasure = rotateOnce(row,col , treasure);
        break;
    default:
        break;
    }

    bfs(treasure, true);
}

int cycle(vector<vector<int>> &treasure ){
    vector<int> degrees = {90, 180, 270};

    int max  = -100;
    int deg = -1;
    int row = -1;
    int col = -1;

    for(auto degs : degrees){
        for( int r = 1 ; r < 4 ; r++){
            for(int c = 1 ; c < 4 ; c ++){
                int ret = rotationAndCheck(degs, r,c, treasure);            
                if(ret > max){
                    max = ret;
                    row = r;
                    col = c;
                    deg = degs;
                }
            }
        }
    }
    if(max == 0){
        return 0;
    }else{
        rotationAndDelete(deg, row, col, treasure);
        return max;
    }


    
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int tryNum ; 
    int treasureCount;

    cin >> tryNum >> treasureCount;

    vector <vector<int>> treasure(5, vector<int>(5));

    for (int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j < 5 ; j++){
            cin >> treasure[i][j];
        }
    }

    

    for (int i = 0 ; i < treasureCount ; i++){
        int temp;
        cin >> temp;
        treasureQ.push(temp);
    }

    for(int turn = 0 ; turn < tryNum ; turn ++){

        int thisCycle = cycle(treasure);
        int ans = thisCycle;
        if(ans == 0){
            return 0;
        }
        
        while(1){
            int trial = bfs(treasure, true);

            if(trial == 0){
                break;
            }else{
                ans += trial;
            }
        }
        cout << ans << ' ';
    }

    // cout << ans;

    
    

    //   for(auto i : treasure){
    //     for(auto j : i){
    //         cout << j;
    //     }
    //     cout << endl;
    // }

    return 0;
}