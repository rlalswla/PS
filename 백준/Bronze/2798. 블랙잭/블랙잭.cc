#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    

    int N, M;
    cin >> N >> M;
    
    vector<int> numbers(N);
    for( int i = 0 ; i < N ; i++){
        cin >> numbers[i];
    }
    int max = -1000000;

    for(int i = 0; i < N-2; i++){
        for(int j = i+1; j < N-1; j++){
            for(int k = j+1; k < N; k++){
                int sum = numbers[i] + numbers[j] + numbers[k];
                if(sum <= M){
                    if(sum > max){
                        max = sum;
                    }
                }
            }
        }
    }

    cout << max;

    return 0;
}