#include <vector>
#include <string>
#include <iostream>

using namespace std;
int ans =0;

void find(int row, int col, vector<vector<int>> & v  ){
    v[row][col] = 2;
    if(row+1 <= v.size()-1 && v[row+1][col]==1){
        find(row+1,col , v);
    }
    if (row-1 >= 0 && v[row-1][col]==1){
        find(row-1,col ,v );
    }
    if (col+1 <= v[0].size() && v[row][col+1]==1){
        find(row,col+1 ,v );
    }
    if (col -1 >= 0 && v[row][col-1]==1){
        find(row,col-1 ,v );
    }

}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    
    for(int i = 0; i < N; i++){
        ans = 0;
        int row,col,tc;
        cin >>row>>col>>tc;
        vector<vector<int>>v (row,vector<int>(col,0));   

        for(int j = 0 ; j < tc ; j ++){
            int a , b;
            cin >> a >> b;
            v[a][b] = 1;    
        }

        for(int s = 0 ; s < row ; s ++ ){
            for(int t = 0 ; t < col ; t ++){
                if(v[s][t] == 1){
                    
                    find(s,t, v);
                    
                    ans++;
                }
            }
        }
        
        cout << ans <<'\n';

    }

    return 0;
}