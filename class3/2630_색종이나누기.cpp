#include <vector>
#include <string>
#include <iostream>

using namespace std;

int blue=0;
int white =0;


void devide(vector<vector<int>> v ,int startx, int starty, int length){
    int color = v[startx][starty];
    bool same = true;
    for( int i = 0; i < length ; i++){
        for(int j = 0 ; j < length ; j ++){
            if(v[startx+i][starty+j] != color){
                same = false;
                break;
            }
        }
        if(same == false){
            break;
        }
    }

    if(same == true){
        if(color == 1){
            blue ++;
        }
        else{
            white ++;
        }
    }
    else{
        devide(v,startx+length/2 , starty+length/2,length/2);
        devide(v,startx , starty+length/2,length/2);
        devide(v,startx+length/2 , starty,length/2);
        devide(v,startx , starty,length/2);
    }
    
}

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> v(N);

    for(int i = 0; i < N; i++){
        for(int j = 0 ; j < N ; j++){
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
    devide(v,0,0,N);
    cout << white << '\n' << blue << '\n';



    return 0;
}