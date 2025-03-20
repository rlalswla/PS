#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main (){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int maxW;
    cin >> maxW;
    
    vector<int> weights(N+1);
    vector<int> values(N+1);

    vector<int> dp(maxW+1,0);
    for(int i = 1; i < N+1; i++){
        
        cin >> weights[i] >> values[i];
    }

    for(int i = 1 ; i < N+1 ; i++){
        for(int j = maxW ; j >= weights[i] ; j--){
            dp[j] = max(dp[j], dp[j-weights[i]]+values[i]);
             
        }
    }
    cout << dp[maxW] <<endl;


    return 0;
}