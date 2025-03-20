
#include <vector>
#include <string>
#include <iostream>

using namespace std;
int N;
int answer  = 0 ;
vector<int> col;


bool valid (int row){
    for(int i = 0; i < row ; i ++){
        if(col[row] == col[i] || abs(col[row] - col[i]) == row-i){
            return false;
        }
        
    }
    return true;
}

void backtrack (int row){
    if(row == N){
        answer ++;
        return;        
    }

    bool isValid = false;

    for(int i = 0 ; i < N ; i++){
        col[row] = i;
        isValid = valid(row);
        if(isValid) backtrack(row+1);
    }
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N;
    col.resize(N);

    backtrack(0);
    cout <<answer;
    

    return 0;
}