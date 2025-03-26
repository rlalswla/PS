#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

     int N;
    cin >> N;
    
    for(int i = 0; i < N; i++){
        string s;
        cin >> s;
        int score = 1 ;
        int sum = 0 ; 
        for(auto i : s ){
            if(i == 'O'){
                sum += score;
                score++;
            }else{
                score = 1;
            }
        }
        cout << sum << '\n';
    }

    return 0;
}