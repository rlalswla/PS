#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int>v;
    v.resize(N+1);
    
    vector<vector<bool>> dp(N+1,vector<bool>(N+1, false));



    for(int i = 1 ; i < N+1 ; i++){
        cin >> v[i];
    }

    for(int i = 1 ; i < N+1 ; i++){
        dp[i][i] = true;
    }

    for(int i = 1 ; i < N ; i++){
        if(v[i] == v[i+1]){
            dp[i][i+1] = true;
        }
    }
    
    for(int len = 3; len < N+1 ; len++){
        for(int idx = 1 ; idx < N-len+2;idx++){
            if(v[idx] == v[idx+len-1] && dp[idx+1][idx+len-2]){
                dp[idx][idx+len-1] = true;
            }
        }
    }




    int M;
    cin >> M;

    for(int i = 0 ; i < M ; i++){
        int a,b;
        cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
    
    return 0;
}
