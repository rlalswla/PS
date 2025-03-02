#include <iostream>
#include <cmath>
using namespace std;

vector<int>v;

int where(int row,int col ,int s_row, int s_col , int N){
    if(N == 0){
        return 0;
    }
    if(row > s_row){
        if(col > s_col){
            v.push_back(4);
            where(row,col,s_row+N/2,s_col+N/2, N/2);
        }
        else{
            v.push_back(3) ;
            where(row,col,s_row+N/2,s_col-N/2, N/2);
        }
    }
    else{
        if(col > s_col){
            v.push_back(2) ;
            where(row,col,s_row-N/2,s_col+N/2, N/2);
        }
        else{
            v.push_back(1) ;
            where(row,col,s_row-N/2,s_col-N/2, N/2);
        }
    }
    return 0;
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, row , col;
    cin >> a >> row >> col;
    int num = pow(2,a);
    where(row+1,col+1,num/2,num/2,num/2);

    int ans = 0 ; 

    for(int j =0 ; j < a ; j ++){
        
        ans += pow(4,(a-j-1)) * (v[j]-1);
    }

    cout << ans;
    
    
    return 0;
}

