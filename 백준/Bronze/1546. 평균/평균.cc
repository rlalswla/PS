#include <vector>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;



int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N ; 
    cin >> N ;
    vector<float> v(N);
    float MAX = -100;
    for(int i =0; i  < N ; i ++){
         cin >> v[i];
         MAX = max(MAX, v[i]);
    }
    
    for(int i = 0 ; i < v.size() ; i++){
        if( v[i] == MAX){
            v[i] = 100;
        }else{
            v[i] = v[i]/MAX;
            v[i] = v[i] * 100;
        }
    }

    float sum = 0;
    for(auto i : v){
        // cout << i << endl;
        sum += i;
    }
    cout << sum /v.size() <<endl;
    

    return 0;
}