#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> board(9,vector<int>(9));

bool isValid(int i, int j , int k){
    for(int row = 0 ; row < 9 ; row ++){
        if(board[row][j] == k || board[i][row] == k){
            return false;
        }
    }
    int startR , startC;
    startR = i/3;
    startR = startR*3;
    startC = j/3;
    startC = startC*3;
    for(int row = 0 ; row < 3 ; row ++){
        for(int col = 0 ; col < 3 ; col ++){

            if(board[startR+row][startC+col] == k){
                return false;
            }
        }
    }
    return true;
}

bool solve (){
    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            if(board[i][j] == 0){
                for(int k = 1 ; k < 10 ; k++){

                    if(isValid(i,j,k)){
                        board[i][j] = k ;
                        if(solve()) return true;
                        board[i][j]=0;
                    }
                }
                return false;
            }
            
        }
    }    
    return true;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    for(int i = 0 ; i < 9 ; i++){
            
            string s ;
            cin >> s;
            for(int j = 0 ; j < 9 ; j++){
                char c;
                c = s[j];
                board[i][j]= c-'0';
            }
            

       
    }

    solve();

    for(int i = 0 ; i < 9 ; i++){
        for(int j = 0 ; j < 9 ; j++){
            cout << board[i][j];
        }
        cout << '\n';
    }

    return 0;
}