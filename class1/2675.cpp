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
        int a;
        cin >> a;
        string s;
        cin >> s;
        for( auto it: s){
            for(int j = 0 ; j < a ; j++){
                cout << it; 
            } 
        }
        cout << '\n';
    }

    return 0;
}